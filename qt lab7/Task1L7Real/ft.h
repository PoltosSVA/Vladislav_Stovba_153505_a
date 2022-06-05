#include <iostream>
#include <iomanip>
#include <list>
using namespace std;

template <typename A, typename B>
class Node {
public:

    pair<A, B> p;//key and value

    int height;

    Node<A, B>* left;
    Node<A, B>* right;
    Node<A, B>* parent = nullptr;

};
template <typename A, typename B>
class Tree {
public:

    Node<A, B>* root;

public:

    class Iterator {
    private:
        Node<A, B>* ptr;
        Node<A, B>* rooti;
    public:
        Iterator(Node<A, B>* pt, Node<A, B>* ro) :ptr(pt), rooti(ro) {}


        bool operator== (const Iterator& other) const {
            return ptr == other.ptr;
        }

        bool operator!= (const Iterator& other) const {
            return !(ptr == other.ptr);
        }


        pair<A, B> operator* () const {
            return ptr->p;
        }


        Iterator& operator ++() {



            if (ptr == nullptr)
            {

                ptr = rooti;


                if (ptr == nullptr)
                {
                    return *this;
                }


                while (ptr->left != nullptr) {
                    ptr = ptr->left;
                }
            }
            else
                if (ptr->right != nullptr)
                {

                    ptr = ptr->right;

                    while (ptr->left != nullptr) {
                        ptr = ptr->left;
                    }
                }
                else
                {
                    Node<A, B>* p = ptr->parent;
                    p = ptr->parent;
                    while (p != nullptr && ptr == p->right)
                    {
                        ptr = p;
                        p = p->parent;
                    }


                    ptr = p;
                }

            return *this;
        }

        Iterator& operator=(const Iterator& other) {
            rooti = other.rooti;
            ptr = other.ptr;

            return *this;
        }

        Iterator& operator-- () {
            if (ptr == nullptr) {
                ptr = rooti;

                if (ptr == nullptr)
                    return *this;

                while (ptr->right != nullptr) {
                    ptr = ptr->right;
                }
            }
            else if (ptr->left != nullptr) {
                ptr = ptr->left;

                while (ptr->right != nullptr) {
                    ptr = ptr->right;
                }
            }
            else {
                Node<A, B>* p = ptr->parent;
                while (p != nullptr && ptr == p->left) {
                    ptr = p;
                    p = p->parent;
                }

                ptr = p;
            }
            return *this;
        }


    };

    list<Node<A, B>*> tree_l;

    void inorder_sec(Node<A, B>* n) {
        if (n != nullptr) {
            inorder_sec(n->left);
            tree_l.push_back(n);
            inorder_sec(n->right);
        }
    }

    class Iterator_List {
    private:
        list<Node<A, B>*> tree_list;
        typename list<Node<A, B>*>::iterator it;

    public:
        Iterator_List(const list<Node<A,B>*>& other, bool begin) {
            tree_list = other;

            if (begin)
                it = tree_list.begin();
            else
                it = tree_list.end();
        }

        pair<A,B> operator*() {
            return (*it)->p;
        }

        Iterator_List& operator++() {
            ++it;
            return *this;
        }

        Iterator_List& operator--() {
            --it;
            return *this;
        }

    };

    Iterator_List begin_list() {

        tree_l.clear();

        inorder_sec(Tree<A,B>::root);

        return Iterator_List(tree_l, true);
    }

    Iterator_List end_list() {

        tree_l.clear();

        inorder_sec(Tree<A, B>::root);

        return Iterator_List(tree_l, false);
    };

    Iterator inserti(pair<A, B> item) {
        Tree<A, B>::insert(item);
        return Iterator(Tree<A, B>::root);
    }

    Iterator erase(const A& key) {
        Tree<A, B>::Remove(key);
        return Iterator(Tree<A, B>::root);
    }

    Iterator begin() {
        Node<A, B>* node = Tree<A, B>::root;

        while (node->left != nullptr) {
            node = node->left;
        }

        return Iterator(node, Tree<A, B>::root);
    }

    Iterator end() {
        return Iterator(nullptr, Tree<A, B>::root);
    }

    Tree() :root(nullptr) {}

    Tree(pair<A, B> par) {

        root = new Node<A, B>;

        root->p = par;

        root->left = nullptr;

        root->right = nullptr;

    }

    Node<A, B>* Search(Node<A, B>* Root, A par) {
        if (root == nullptr) {

            return root;

        }

        else if ((Root->p.first > par && Root->left == nullptr) || (Root->p.first < par && Root->right == nullptr)) {
            return  Root;
        }
        else if (Root->p.first == par) {

            return  Root;

        }
        else if (par > Root->p.first) {

            Search(Root->right, par);


        }
        else if (par < Root->p.first) {

            Search(Root->left, par);

        }

    }

    void insert(pair<A, B> par) {
        Node<A, B>* node = new Node<A, B>;

        if (root == nullptr) {

            Node<A, B>* temp = new Node<A, B>;

            temp->p = par;

            temp->left = nullptr;
            temp->right = nullptr;

            root = temp;

        }
        else {

            node->parent = Search(root, par.first);//находим когда корень равен 0

            node->left = node->right = nullptr;

            node->p = par;



            if (par.first > node->parent->p.first) {//если номер больше то право если нет то влево

                node->parent->right = node;

            }
            else if (par.first < node->parent->p.first) {

                node->parent->left = node;

            }
            Rebalancer(node);
        }


    }

    A Find_Min() {

        Node<A, B>* pre = new Node<A, B>;

        pre = root;

        if (pre->left == nullptr) {

            return pre->p.first;

        }

        while (pre->left != nullptr) {

            pre = pre->left;

        }

        return pre->p.first;

    }

    A Find_Max() {

        Node<A, B>* per = new Node<A, B>;

        per = root;

        if (per->right == nullptr) {
            return per->p.first;
        }

        while (per->right != nullptr) {


            per = per->right;

        }

        return per->p.first;

    }

    Node<A, B>* Successor(Node<A, B>* sucessee) {//++

        if (sucessee->right != nullptr) {

            Node<A, B>* per = new Node<A, B>();

            per = sucessee->right;

            if (per->left == nullptr) {
                return per;
            }

            while (per->left != nullptr) {

                per = per->left;

            }

            return per;

        }
        else {

            Node<A, B>* per = new Node<A, B>;

            per = sucessee;

            while (per->p.first > per->parent->p.first) {

                per = per->parent;

            }

            return per->parent;

        }
    }

    int standart = 0;

    B& operator[](A par) {

        Node<A, B>* n;
        Tree<A,B> abc;
        n = this->Search(root,par);

        if(n) {
            return n->p.second;
        } else

        {
            pair<A, B> pair;

            pair.first = par;
            pair.second = standart;

            Node<A, B>* nn = new Node<A, B>;
            nn->p=pair;
            abc.insert(nn->p);



            return nn->p.second;
        }




    }

    void disp() {

        display(root, 10);

    }

    void RemoveNode(Node<A,B>* Parent, Node<A, B>* cur, int it) {
        if (cur == nullptr) {
            return;
        }

        if (cur->p.first == it) {

            if (cur->left == nullptr && cur->right == nullptr) {

                if (Parent->p.first == cur->p.first) {
                    root = nullptr;
                }
                else if (Parent->right == cur) {
                    Parent->right = nullptr;
                }
                else {
                    Parent->left = nullptr;
                }

                Rebalancer(Parent);
            }

            else if (cur->left != nullptr && cur->right == nullptr) {

                int sp = cur->p.first;

                cur->p.first = cur->left->p.first;

                cur->left->p.first = sp;

                RemoveNode(cur, cur->left, it);
            }
            else if (cur->left == nullptr && cur->right != nullptr) {

                int sp = cur->p.first;

                cur->p.first = cur->right->p.first;
                cur->right->p.first = sp;

                RemoveNode(cur, cur->right, it);
            }

            else {
                Node<A,B>* temp = cur->right;

                int flag = 0;

                while (temp->left) {
                    flag = 1;
                    Parent = temp;
                    temp = temp->left;
                }

                if (!flag) {
                    Parent = cur;
                }

                int sp = cur->p.first;

                cur->p.first = temp->p.first;

                temp->p.first = sp;

                RemoveNode(Parent, temp, temp->p.first);
            }
        }
    }

    void Remove(int it) {

        auto temp = root;

        auto Parent = temp;



        if (temp == nullptr) {
            RemoveNode(nullptr, nullptr, it);
        }

        while (temp) {
            if (it == temp->p.first) {

                RemoveNode(Parent, temp, it);
                break;
            }
            else if (it < temp->p.first) {
                Parent = temp;
                temp = temp->left;
            }
            else {
                Parent = temp;
                temp = temp->right;
            }
        }


    }

    void display(Node<A, B>* p, int indent) {//+++

        if (p != nullptr) {

            if (p->right) {

                display(p->right, indent + 4);

            }

            if (indent) {

                std::cout << setw(indent) << ' ';

            }
            if (p->right) std::cout << " /\n" << setw(indent) << ' ';
            std::cout << p->p.first << "\n ";
            if (p->left) {
                std::cout << setw(indent) << ' ' << " \\\n";
                display(p->left, indent + 4);
            }
        }
        else { return; }
    }

    void preorder(Node<A, B>* index) {//++
        if (index != nullptr) {
            std::cout << index->p.first << " ";
            preorder(index->left);
            preorder(index->right);
        }
    }

    void postorder(Node<A, B>* index) {//++
        if (index != nullptr) {
            postorder(index->left);


            postorder(index->right);
            std::cout << index->p.first << " ";
        }
    }

    void inorder(Node<A, B>* index) {//++
        if (index != nullptr) {
            inorder(index->left);
            std::cout << index->p.first << " ";
            inorder(index->right);
        }
    }

    int getHight(Node<A, B>* temp) {
        return ((temp == nullptr) ? -1 : temp->height);//определение высоты
    }

    int CheckHight(Node<A, B>* temp) {
        if (temp != nullptr) {
            int a = getHight(temp->right);
            int b = getHight(temp->left);

            int re = a - b;

            return re;//разность высот
        }
        return 0;
    }

    void CalculateHight(Node<A, B>* temp) {
        int lef = -1;
        int rig = -1;

        if (temp->left) {
            lef = temp->left->height;//значение высоты в одной из ветвей
        }

        if (temp->right) {
            rig = temp->right->height;
        }

        temp->height = max(lef, rig) + 1;//нахождение ветви с  большей высотой
    }

    void TreeFix(Node<A, B>* temp) {

        if (CheckHight(temp) == 2) {//если небаланс дерево

            if (CheckHight(temp->right) < 0) {//правое минус левое если минус то поворот вправо
                RightRotate(temp->right);
            }

            LeftRotate(temp);//нет то влево

            CalculateHight(temp);//чекаем высоту
        }
        else if (CheckHight(temp) == -2) {//наооборот

            if (CheckHight(temp->left) > 0) {
                LeftRotate(temp->left);
            }

            RightRotate(temp);

            CalculateHight(temp);
        }
    }

    void Rebalancer(Node<A, B>* temp) {

        if (temp == root) {
            TreeFix(root);
        }
        else {
            while (temp != nullptr) {

                CalculateHight(temp);

                temp = temp->parent;

                if (temp) {
                    TreeFix(temp);
                }
            }
        }
    }

    void LeftRotate(Node<A, B>* x) {

        Node<A, B>* nw_node = new Node<A, B>();

        if (x->right->left) {

            nw_node->right = x->right->left;

        }
        nw_node->left = x->left;

        nw_node->p = x->p;

        x->p = x->right->p;

        x->left = nw_node;

        if (nw_node->left) {

            nw_node->left->parent = nw_node;
        }
        if (nw_node->right) {
            nw_node->right->parent = nw_node;
        }

        nw_node->parent = x;

        if (x->right->right) {

            x->right = x->right->right;

        }
        else {
            x->right = nullptr;
        }

        if (x->right) {
            x->right->parent = x;
        }

        CalculateHight(x->left);

        if (x->right) {
            CalculateHight(x->right);
        }

        CalculateHight(x);
    }

    void RightRotate(Node<A, B>* x) {

        Node<A, B>* nw_node = new Node<A, B>();

        if (x->left->right) {
            nw_node->left = x->left->right;
        }

        nw_node->right = x->right;
        nw_node->p = x->p;
        x->p = x->left->p;

        x->right = nw_node;

        if (nw_node->left) {
            nw_node->left->parent = nw_node;
        }
        if (nw_node->right) {
            nw_node->right->parent = nw_node;
        }

        nw_node->parent = x;

        if (x->left->left) {
            x->left = x->left->left;
        }
        else {
            x->left = nullptr;
        }

        if (x->left) {
            x->left->parent = x;
        }

        CalculateHight(x->right);
        if (x->left) {
            CalculateHight(x->left);
        }

        CalculateHight(x);
    }

};
