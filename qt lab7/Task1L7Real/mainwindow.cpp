#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateTable()
{
    ui->treeWidget->clear();
    Node* root = tree.root;
    if(!root) {
        return;
    }
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0, QString::fromStdString(std::to_string(root->p.first)));
    item->setText(1, QString::fromStdString(std::to_string(root->p.second)));
    ui->treeWidget->addTopLevelItem(item);
    PreOrderUpdateTable(root, item);

}

void MainWindow::PreOrderUpdateTable(Node *node, QTreeWidgetItem *parent)
{
    if(node->left) {
        Node* child = node->left;
        QTreeWidgetItem *lchild = new QTreeWidgetItem();
        lchild->setText(0, QString::fromStdString(std::to_string(child->p.first)));
        lchild->setText(1, QString::fromStdString(std::to_string(child->p.second)));
        parent->addChild(lchild);
        PreOrderUpdateTable(child, lchild);
    }
    if(node->right) {
        Node* child = node->right;
        QTreeWidgetItem *rchild = new QTreeWidgetItem();
        rchild->setText(0, QString::fromStdString(std::to_string(child->p.first)));
        rchild->setText(1, QString::fromStdString(std::to_string(child->p.second)));
        parent->addChild(rchild);
        PreOrderUpdateTable(child, rchild);
    }
}




void MainWindow::on_pushButton_clicked()
{


    tree.insert(std::make_pair(ui->spinBox->value(), ui->spinBox_2->value()));
    UpdateTable();
}


void MainWindow::on_pushButton_2_clicked()
{
    tree.Remove(ui->spinBox_3->value());
    UpdateTable();
}


void MainWindow::on_pushButton_3_clicked()
{
    if(tree.root!= nullptr){

    QString string;

    Node* a = tree.Search(tree.root,ui->spinBox_4->value());
    if(a->p.first==ui->spinBox_4->value()) {
        string = "true";
    } else {
        string = "false";
    }
    ui->textEdit->setText(string);
}

}
void MainWindow::on_pushButton_4_clicked()
{
    if(tree.root!=nullptr){
    QString string;

    Node* a = tree.Search(tree.root,ui->spinBox_5->value());
    if(a->p.first==ui->spinBox_5->value()) {
        string = QString::number(a->p.second);
         ui->textEdit->setText(string);
    } else {
        tree.insert(make_pair(ui->spinBox_5->value(),0));
        UpdateTable();
    }
}



}
