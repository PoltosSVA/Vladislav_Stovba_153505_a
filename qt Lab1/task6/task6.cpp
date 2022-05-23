#include <iostream>
using namespace std;

class Expression {
public:
    virtual double evaluate() const = 0;
    virtual ~Expression() {}
};

class Number :public Expression {
public:
    Number(double value) :value(value) {}
    ~Number() {}
    virtual double evaluate() const { return value; }
private:
    double value;
};

class HNumber :public Expression {
public:
    HNumber(double value) :value(value) {}
    ~HNumber() {}
    virtual double evaluate() const { return value; }
private:
    double value;
};

class HuNumber :public Expression {
public:
    HuNumber(double value) :value(value) {}
    ~HuNumber() {}
    virtual double evaluate() const { return value; }
private:
    double value;
};

class BinaryOperation :public Expression {
public:
    BinaryOperation(Expression const* left, char op, Expression const* right) :left(left), op(op), right(right) {}

    virtual double evaluate()const {
        if (op == '+') {
            return (left->evaluate() + right->evaluate());
        }
        else if (op == '-') {
            return (left->evaluate() - right->evaluate());
        }
        else if (op == '*') {
            return (left->evaluate() * right->evaluate());
        }
        else if (op == '/') {
            return (left->evaluate() / right->evaluate());
        }

    }
    ~BinaryOperation() {
        delete right;
        delete left;
    }
private:
    Expression const* left;
    Expression const* right;
    char op;


};
bool check_equals(Expression const* left, Expression const* right) {
    
    return(*((size_t*)left) == *((size_t*)right));
}

int main() {

    Expression* sube = new BinaryOperation(new BinaryOperation(new Number(2),'*',new Number(5)),'+',new BinaryOperation(new Number(2),'*',new Number(5)));
    Expression* expr = new BinaryOperation(new Number(2), '+', new Number(5));
    Expression* num = new Number(3);
    //Expression* sube = new HNumber(45);
    //Expression* expr = new HuNumber(5);
    //Expression* exp = new Number(5);
    std::cout<<endl<< check_equals(new Number(10), new Number(3));

    std::cout << endl << check_equals(sube, expr);
    std::cout << endl << check_equals(num, expr);
    //std::cout << expr->evaluate();
    delete expr;
}








