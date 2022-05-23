#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <regex>
#include <vector>
#include <string>
#include <QDebug>
#include <QStandardItemModel>
#include <QModelIndex>
#include <QMessageBox>
#include <stack>
#include <QFileDialog>

#include "D:\LIB\strlib\strlib.h"

class Variable {

private:
    std::string m_type;
    std::string m_name;
    std::string m_value;

    size_t x_cord = 0;
    size_t y_cord = 0;

    bool isLocal;
public:
    Variable(std::string type, std::string name, std::string value) :
            m_type(std::move(type)),
            m_name(std::move(name)),
            m_value(std::move(value)) {}



    std::string GetType() {
        return m_type;
    }
    std::string GetName() {
        return m_name;
    }

    std::string GetValue() {
        return m_value;
    }
    size_t GetXCord() {
        return x_cord;
    }
    size_t GetYCord() {
        return y_cord;
    }
    bool GetLocal() {
        return isLocal;
    }

    void SetXCord(size_t value) {
        x_cord = value;
    }
    void SetYCord(size_t value) {
        y_cord = value;
    }
    void SetLocal(bool value) {
         isLocal = value;
    }
};



class Function {
private:
    std::string m_type;
    std::string m_name;
    std::string m_value;

    size_t x_cord;
    size_t y_cord;
public:
    Function(std::string type, std::string name, std::string value) :
            m_type(std::move(type)),
            m_name(std::move(name)),
            m_value(std::move(value)) {}




    std::string GetType() {
        return m_type;
    }

    std::string GetName() {
        return m_name;
    }

    std::string GetValue() {
        return m_value;
    }

    size_t GetXCord() {
        return x_cord;
    }
    size_t GetYCord() {
        return y_cord;
    }
    void SetXCord(size_t value) {
        x_cord = value;
    }
    void SetYCord(size_t value) {
        y_cord = value;
    }

};

class Class {
private:
    std::string m_type;
    std::string m_name;

    size_t x_cord;
    size_t y_cord;

    bool isLocal = false;
public:
    Class(std::string type, std::string name) :
            m_type(std::move(type)),
            m_name(std::move(name)) {}




    std::string GetType() {
        return m_type;
    }

    std::string GetName() {
        return m_name;
    }

    size_t GetXCord() {
        return x_cord;
    }
    size_t GetYCord() {
        return y_cord;
    }
    bool GetLocal() {
        return isLocal;
    }

    void SetXCord(size_t value) {
        x_cord = value;
    }
    void SetYCord(size_t value) {
        y_cord = value;
    }
    void SetLocal(bool value) {
         isLocal = value;
    }

};

class ChangeVariable {
private:
    std::string m_name;
    size_t x_cord;
    size_t y_cord;

public:
    ChangeVariable( std::string name, size_t x, size_t y) :
        m_name(name), x_cord(x), y_cord(y) {}
    size_t GetXCord() {
        return x_cord;
    }
    size_t GetYCord() {
        return y_cord;
    }

    void SetXCord(size_t value) {
        x_cord = value;
    }
    void SetYCord(size_t value) {
        y_cord = value;
    }

    std::string GetName() {
        return m_name;
    }
    void SetName( std::string& value) {
        m_name = value;
    }
};

class Struct {
private:
    std::string m_type;
    std::string m_name;

    size_t x_cord;
    size_t y_cord;

    bool isLocal;
public:
    Struct(std::string type, std::string name) :
            m_type(std::move(type)),
            m_name(std::move(name)) {}



    std::string GetType() {
        return m_type;
    }

    std::string GetName() {
        return m_name;
    }

    size_t GetXCord() {
        return x_cord;
    }
    size_t GetYCord() {
        return y_cord;
    }
    bool GetLocal() {
        return isLocal;
    }

    void SetXCord(size_t value) {
        x_cord = value;
    }
    void SetYCord(size_t value) {
        y_cord = value;
    }
    void SetLocal(bool value) {
         isLocal = value;
    }


};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void CheckLine(String line);
    void UpdateModelVariables();
    void UpdateModelPrototypes();
    void UpdateModelOverload();
    void UpdateModelChangeVariable();
    void UpdateModelBranchingDepth();
    void UpdateCountVariables();
    void ResetAll();
    void ReadFile();
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:

    QString filePath;
    String text;


    Ui::MainWindow *ui;
    size_t countArrayInit = 0;
    size_t countClassInit = 0;
    size_t countStructInit = 0;

    size_t countLocal = 0;
    size_t countLocalAfterIf = 0;


    bool AfterClose = false;
    bool Error = false;
    bool isCycle = false;
    bool hasBreak = false;
    bool isFile = false;

    size_t currentXCord = 1;
    size_t currentYCord = 1;


    std::vector<int> list_trueCycle;

    std::vector<Variable> list_variable;
    std::vector<Function>    list_function;
    std::vector<Class> list_class;
    std::vector<Struct> list_struct;
    std::vector<ChangeVariable> list_changeVariable;
    std::vector<size_t> list_branchingDepth;

    QStandardItemModel *model_variables;
    QStandardItemModel *model_prototypes;
    QStandardItemModel *model_change;
    QStandardItemModel *model_overload;
    QStandardItemModel *model_branchingDepth;


    std::regex isFuncPrototype {R"((\s*)(const)?(\s*)((((unsigned)|(signed))?(\s*)((void)|(bool)|(char)|(short)|(int)|(long)))|((double)|(float)|(bool)))(\s*)(\w+)(\s*)(\()(.*)(\))(\s*)(\;)(\r)?)"};
    std::regex isVal           {R"((\s*)(const)?(\s*)((((unsigned)|(signed))?(\s*)((void)|(bool)|(char)|(short)|(int)|(long)))|((double)|(float)|(bool)))(.+)(\;)(\r)?)"};
    std::regex isFunc {R"((\s*)(const)?(\s*)((((unsigned)|(signed))?(\s*)((void)|(bool)|(char)|(short)|(int)|(long)))|((double)|(float)|(bool)))?(\s*)(\w+)(\s*)(\()(.*)(\))(\s*)(\{)(\r)?)"};
    std::regex isClass {R"((\s*)(class)(\s*)([^\s]+)(\s*)(\:*)(\s*)([^\s]*)(\s*)(\{)(\r)?)"};
    std::regex isStruct {R"((\s*)(struct)(\s*)([^\s]+)(\s*)(\:*)(\s*)([^\s]*)(\s*)(\{)(\r)?)"};

    std::regex isIf {R"((\s*)(if)(\s*)(\()(.*)(\))(\s*)(\{)(\s*)(\r)?)"};
    std::regex isElse {R"((\s*)(\})(\s*)(else)(\s*)(\{)(\s*)(\r)?)"};

    std::regex isWhile {R"((\s*)(while)(\s*)(\()(\s*)(.*)(\s*)(\))(\s*)(\{)(\s*)(\r)?)"};
    std::regex isFor {R"((\s*)(for)(\s*)(\()(\s*)(.*)(\s*)(\;)(\s*)(.*)(\s*)(\;)(\s*)(.*)(\s*)(\))(\s*)(\{)(\s*)(\r)?)"};
    std::regex isBreak {R"((\s*)(break)(\s*)(\;)(\r)?)"};

    std::regex partComVal {R"((\s+)?(\*)?(\s+)?(\w+)(\s+)?(.+)(\r)?)"};

    std::regex defInitVal {R"((\s*)(\**)(\s*)(\w+)(\s*)(\=)(\s*)([^\s]+)(\s*)(\r)?)"};
    std::regex uniInitVal {R"((\s*)(\**)(\s*)(\w+)(\s*)(\{)(.*)(\})(\s*)(\r)?)"};
    std::regex funInitVal {R"((\s*)(\**)(\s*)(\w+)(\s*)(\()(.*)(\))(\s*)(\r)?)"};
    std::regex defInitArr {R"((\s*)(\**)(\s*)(\w+)(\s*)(\[)(.*)(\])(\s*)(\r)?)"};
    std::regex listInitArr {R"((\s*)(\**)(\s*)(\w+)(\s*)(\[)(.*)(\])(\s*)(\=*)(\s*)(\{)(.*)(\})(\s*)(\r)?)"};
    std::regex emptyVal {R"((\s*)(\**)(\s*)(\w+)(\s*)(\r)?)"};
    std::regex defInitClass {R"((\s*)(\w+)(\s*)(\()(.*)(\))(\s*)(\r)?)"};
    std::regex refInitClass {R"((\s*)(\**)(\s*)(\w+)(\s*)(\=)(\s*)(new)(\s*)(\w+)(\()(.*)(\))(\s*)(\r)?)"};
    std::regex emptyInitClass {R"((\s*)(\w+)(\s*)(\r)?)"};


    std::regex isRef {R"(([^\*]*)(\**)(.*)(\r)?)"};

    std::regex closeLocal {R"((\s*)(\})(\;)?(\s*)(\r)?)"};

    std::regex partExpression {R"((([^,{(]*)((\(|\{)[^)}]*(\)|\}))?)(\,*)(.*)(\r)?)"};
};
#endif // MAINWINDOW_H
