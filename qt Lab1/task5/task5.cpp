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
    ~Number(){}
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

int main() {
    Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression* expr = new BinaryOperation(new Number(3), '+', sube);
        std::cout << expr->evaluate();
    delete expr;
}








