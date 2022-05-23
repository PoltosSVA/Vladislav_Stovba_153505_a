#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(900,500);

    model_variables = new QStandardItemModel(0, 4);
    model_variables->setHeaderData(0, Qt::Horizontal, "Тип");
    model_variables->setHeaderData(1, Qt::Horizontal, "Имя");
    model_variables->setHeaderData(2, Qt::Horizontal, "Значение");
    model_variables->setHeaderData(3, Qt::Horizontal, "Координата");

    model_prototypes = new QStandardItemModel(0, 1);
    model_prototypes->setHeaderData(0,Qt::Horizontal, "Прототипы");

    model_overload = new QStandardItemModel(0, 2);
    model_overload->setHeaderData(0,Qt::Horizontal, "Перегрузки");
    model_overload->setHeaderData(1,Qt::Horizontal, "Координаты");

    model_change = new QStandardItemModel(0, 2);
    model_change->setHeaderData(0,Qt::Horizontal, "Переменная");
    model_change->setHeaderData(1,Qt::Horizontal, "Место изменения");

    model_branchingDepth = new QStandardItemModel(0, 1);
    model_branchingDepth->setHeaderData(0, Qt::Horizontal, "Глубина вложений");

    ui->tableView->setModel(model_variables);
    ui->tableView_2->setModel(model_prototypes);
    ui->tableView_3->setModel(model_change);
    ui->tableView_4->setModel(model_overload);
    ui->tableView_5->setModel(model_branchingDepth);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ResetAll();
    size_t i = 0;

    if(!isFile) {
        text = ui->textEdit->toPlainText().toStdString();
    } else {
        ui->textEdit->setText(text.c_str());
    }
    String line = "";

    countLocal = 0;
    while(i < text.size() && !Error) {
        while(text[i] != '\n' && i < text.size()) {
            line.push_back(text[i++]);
        }
        i++;
        CheckLine(line);
        currentXCord++;
        currentYCord = 1;
        line = "";
    }
    if(countLocal > 0) {
        QMessageBox::information(this, "Ошибка", "Не хватает }");
        Error = true;
    } else if(countLocal < 0) {
        QMessageBox::information(this, "Ошибка", "Не хватает {");
        Error = true;
    }
    if(!Error) {
        UpdateModelVariables();
        UpdateModelPrototypes();
        UpdateCountVariables();
        UpdateModelChangeVariable();
        UpdateModelOverload();
        UpdateModelBranchingDepth();
    }
    isFile = false;
}

void MainWindow::ResetAll()
{
    countArrayInit = 0;
    countClassInit = 0;
    countStructInit = 0;
    list_class.clear();
    list_function.clear();
    list_struct.clear();
    list_variable.clear();
    list_changeVariable.clear();
    list_branchingDepth.clear();
    list_trueCycle.clear();
    currentXCord = 1;
    currentYCord = 1;
    countLocal = 0;
    countLocalAfterIf = 0;
    AfterClose = false;
    Error = false;
    hasBreak = false;
    model_branchingDepth->setRowCount(0);
    model_change->setRowCount(0);
    model_overload->setRowCount(0);
    model_prototypes->setRowCount(0);
    model_variables->setRowCount(0);
    ui->label_array->setText("");
    ui->label_class->setText("");
    ui->label_struct->setText("");

}




void MainWindow::CheckLine(String line)
{
    std::cmatch result;


    if(std::regex_match(line.c_str(), result, isIf)) {
        countLocalAfterIf++;
        countLocal++;
        AfterClose = false;
        return;
    }
    if(std::regex_match(line.c_str(), result, isElse)) {
        if(!AfterClose) {
        list_branchingDepth.push_back(countLocalAfterIf);
        }
        AfterClose = false;
        return;
    }

    if(std::regex_match(line.c_str(), result, closeLocal)) {
        if(countLocalAfterIf > 0) {
            if(!AfterClose) {
                list_branchingDepth.push_back(countLocalAfterIf);
                AfterClose = true;
            }
            countLocalAfterIf--;
        }
        countLocal--;
        if(!list_trueCycle.empty()) {
            if(list_trueCycle[list_trueCycle.size() - 1] == countLocal) {
                list_trueCycle.pop_back();
                if(!hasBreak) {
                    QMessageBox::information(this, "Ошибка", "Бесконечный цикл");
                    Error = true;
                    return;
                } else {
                    hasBreak = false;
                }
            }
        }
        return;
    }

    if(std::regex_match(line.c_str(), result, isBreak)) {
        hasBreak = true;
    }

    if(std::regex_match(line.c_str(), result, isWhile)) {
        if(result[6] == "false") {
            QMessageBox::information(this, "Ошибка", "while(false)");
            Error = true;
            return;
        }
        if(result[6] == "true") {
            list_trueCycle.push_back(countLocal);
        }
        for(auto i : list_variable) {
            if((std::string)result[6] == i.GetName() && i.GetValue() == "false") {
                QMessageBox::information(this, "Ошибка", "while(false)");
                Error = true;
                return;
            } else {
                if(result[6] == i.GetName() && i.GetValue() == "true") {
                    list_trueCycle.push_back(countLocal);
                }
            }
        }
        countLocal++;
        return;
    }

    if(std::regex_match(line.c_str(), result, isFor)) {
        if(result[10] == "false") {
            QMessageBox::information(this, "Ошибка", "for(false)");
            Error = true;
            return;
        }
        if(result[10] == "true") {
            list_trueCycle.push_back(countLocal);
        }
        for(auto i : list_variable) {
            if(result[10] == i.GetName() && i.GetValue() == "false") {
                QMessageBox::information(this, "Ошибка", "for(false)");
                Error = true;
                return;
            } else {
                if(result[10] == i.GetName() && i.GetValue() == "true") {
                    list_trueCycle.push_back(countLocal);
                }
            }
        }
        countLocal++;
        return;
    }



    if(std::regex_match(line.c_str(), result, isFunc)) {
        bool IsSame = false;
        String currentFunc;
        currentFunc += (std::string)result[4] + (std::string)result[22] + (std::string)result[25];
        for(auto i : list_function) {
            String otherFunc;
            otherFunc += i.GetType() + i.GetName() + i.GetValue();
            if(otherFunc == currentFunc) {
                IsSame = true;
            }
        }
        if(!IsSame) {
            String temp = (std::string)result[1];
            currentYCord += temp.size();
            list_function.emplace_back(result[4], result[22], result[25]);
            list_function[list_function.size() - 1].SetXCord(currentXCord);
            list_function[list_function.size() - 1].SetYCord(currentYCord);
        }
        countLocal++;
        return;
    }

    if(std::regex_match(line.c_str(), result, isFuncPrototype) && !countLocal) {
        bool IsSame = false;
        String currentFunc;
        currentFunc += (String)result[4] + (String)result[22] + (String)result[25];
        for(auto i : list_function) {
            String otherFunc;
            otherFunc += i.GetType() + i.GetName() + i.GetValue();
            if(otherFunc == currentFunc) {
                IsSame = true;
            }
        }
        if(!IsSame) {
            String temp = (std::string)result[1];
            currentYCord += temp.size();
            list_function.emplace_back(result[4], result[22], result[25]);
            list_function[list_function.size() - 1].SetXCord(currentXCord);
            list_function[list_function.size() - 1].SetYCord(currentYCord);
        }
        return;
    }

    if(std::regex_match(line.c_str(), result, isClass)) {
            list_class.emplace_back(result[2], result[4]);
            countLocal++;
            return;
    }

    if(std::regex_match(line.c_str(), result, isStruct)) {
            list_struct.emplace_back(result[2], result[4]);
            countLocal++;
            return;
    }

    if(std::regex_match(line.c_str(), result, isVal)) {
        String preSize = (std::string)result[1];
        preSize += result[2];
        preSize += result[3];
        preSize += result[4];
        currentYCord += preSize.size();

        String str = (std::string)result[21];
        String part;
        std::string current_type = (std::string) result[2] + (std::string) result[3] + (std::string) result[4];
        while(!str.empty()) {

            std::regex_match(str.c_str(), result, partExpression);
            part = result[1];
            str = result[7];

            if (std::regex_match(part.c_str(), result, uniInitVal)) {
                String preSize = (std::string)result[1];
                currentYCord += preSize.size();
                std::cmatch tempResult;
                if(std::regex_match(part.c_str(), tempResult, isRef)) {
                    std::string temp = tempResult[2];
                    temp += current_type;
                    list_variable.emplace_back(temp, result[4], result[7]);
                } else {
                    list_variable.emplace_back(current_type, result[4], result[7]);
                }
                if(countLocal > 0) {
                    size_t index = list_variable.size() - 1;
                    list_variable[index].SetLocal(true);
                    list_variable[index].SetXCord(currentXCord);
                    list_variable[index].SetYCord(currentYCord);
                }
                currentYCord += part.size();
                continue;
            }

            if (std::regex_match(part.c_str(), result, emptyVal)) {
                String preSize = (std::string)result[1];
                currentYCord += preSize.size();

                std::cmatch tempResult;
                if(std::regex_match(part.c_str(), tempResult, isRef)) {
                    std::string temp = tempResult[2];
                    temp +=current_type;
                    list_variable.emplace_back(temp, result[4], "none");
                } else {
                    list_variable.emplace_back(current_type, result[4], "none");
                }
                if(countLocal > 0) {
                    size_t index = list_variable.size() - 1;
                    list_variable[index].SetLocal(true);
                    list_variable[index].SetXCord(currentXCord);
                    list_variable[index].SetYCord(currentYCord);
                }
                currentYCord += part.size();
                continue;
            }
            if (std::regex_match(part.c_str(), result, defInitVal)) {
                String preSize = (std::string)result[1];
                currentYCord += preSize.size();
                std::cmatch tempResult;
                if(std::regex_match(part.c_str(), tempResult, isRef)) {
                    std::string temp = tempResult[2];
                    temp +=current_type;
                    list_variable.emplace_back(temp, result[4], result[8]);
                } else {
                    list_variable.emplace_back(current_type, result[4], result[8]);
                }
                if(countLocal > 0) {
                    size_t index = list_variable.size() - 1;
                    list_variable[index].SetLocal(true);
                    list_variable[index].SetXCord(currentXCord);
                    list_variable[index].SetYCord(currentYCord);
                }
                currentYCord += part.size();
                continue;
            }
            if (std::regex_match(part.c_str(), result, funInitVal)) {
                String preSize = (std::string)result[1];
                currentYCord += preSize.size();
                std::cmatch tempResult;
                if(std::regex_match(part.c_str(), tempResult, isRef)) {
                    std::string temp = tempResult[2];
                    temp += current_type;
                    list_variable.emplace_back(temp, result[4], result[7]);
                } else {
                    list_variable.emplace_back(current_type, result[4], result[7]);
                }
                if(countLocal > 0) {
                    size_t index = list_variable.size() - 1;
                    list_variable[index].SetLocal(true);
                    list_variable[index].SetXCord(currentXCord);
                    list_variable[index].SetYCord(currentYCord);
                }
                currentYCord += part.size();
                continue;
            }
            if (std::regex_match(part.c_str(), result, defInitArr)) {
                String preSize = (std::string)result[1];
                currentYCord += preSize.size();
                countArrayInit++;
                std::cmatch tempResult;
                if(std::regex_match(part.c_str(), tempResult, isRef)) {
                    std::string temp = tempResult[2];
                    temp += current_type;
                    temp += "[]";
                    list_variable.emplace_back(temp, result[4], "none");
                } else {
                    std::string temp = current_type;
                    temp += "[]";
                    list_variable.emplace_back(temp, result[4], "none");
                }
                if(countLocal > 0) {
                    size_t index = list_variable.size() - 1;
                    list_variable[index].SetLocal(true);
                    list_variable[index].SetXCord(currentXCord);
                    list_variable[index].SetYCord(currentYCord);
                }
                currentYCord += part.size();
                continue;
            }

            if (std::regex_match(part.c_str(), result, listInitArr)) {
                String preSize = (std::string)result[1];
                currentYCord += preSize.size();
                countArrayInit++;
                std::cmatch tempResult;
                std::string tempvalue;
                tempvalue += (std::string) result[12] + (std::string) result[13] + (std::string) result[14];
                if(std::regex_match(part.c_str(), tempResult, isRef)) {
                    std::string temp = tempResult[2];
                    temp += current_type;
                    temp += "[]";
                    list_variable.emplace_back(temp, result[4], tempvalue);
                } else {
                    std::string temp = current_type;
                    temp += "[]";
                    list_variable.emplace_back(temp, result[4], tempvalue);
                }
                if(countLocal > 0) {
                    size_t index = list_variable.size() - 1;
                    list_variable[index].SetLocal(true);
                    list_variable[index].SetXCord(currentXCord);
                    list_variable[index].SetYCord(currentYCord);
                }
                currentYCord += part.size();
                continue;
            }
        }
        return;
    }

    for(auto i : list_variable) {
        std::string regex = "(\\s*)(\\**)(\\s*)(";
        std::string nameVariable = i.GetName();

        regex += nameVariable + ")([^\\w])(\\s*)(.+)(\\;)(\\s*)";
        std::regex isChangeVariable(regex);

        if(std::regex_match(line.c_str(), result, isChangeVariable)) {
            String preSize = (String)result[1] + (String)result[2] + (String)result[3];
            currentYCord += preSize.size();
            list_changeVariable.emplace_back(nameVariable, currentXCord, currentYCord);
            return;
        }
     }


    for(auto i : list_class) {
        std::string regex = "(\\s*)(";
        std::string nameClass = i.GetName();

        regex += nameClass + ")(\\s+)(.+)(\\;)(\\s*)";
        std::regex isInitClass(regex);

        if(std::regex_match(line.c_str(), result, isInitClass)) {
            String part;
            String temp = (std::string)result[4];
            String preSize = (std::string)result[1];
            preSize += result[2];
            preSize += result[3];
            currentYCord += preSize.size();
            while(!temp.empty()) {
                std::regex_match(temp.c_str(), result, partExpression);
                part = result[1];
                temp = result[7];
                countClassInit++;

                if (std::regex_match(part.c_str(), result, defInitClass)) {
                    String preSize = (std::string)result[1];
                    currentYCord += preSize.size();

                    if(result[5] == "" || result[5] == " ") {
                        list_variable.emplace_back(nameClass, result[2], "default");
                    } else {
                        list_variable.emplace_back(nameClass, result[2], result[5]);
                    }
                    if(countLocal > 0) {
                        size_t index = list_variable.size() - 1;
                        list_variable[index].SetLocal(true);
                        list_variable[index].SetXCord(currentXCord);
                        list_variable[index].SetYCord(currentYCord);
                    }
                    currentYCord += part.size() + 1;
                    continue;
                }

                if (std::regex_match(part.c_str(), result, emptyInitClass)) {
                    String preSize = (std::string)result[1];
                    currentYCord += preSize.size();
                    list_variable.emplace_back(nameClass, result[2], "default");
                    if(countLocal > 0) {
                        size_t index = list_variable.size() - 1;
                        list_variable[index].SetLocal(true);
                        list_variable[index].SetXCord(currentXCord);
                        list_variable[index].SetYCord(currentYCord);
                    }
                    currentYCord += part.size() + 1;
                    continue;
                }
                if (std::regex_match(part.c_str(), result, refInitClass)) {
                    String preSize = (std::string)result[1];
                    currentYCord += preSize.size();
                    if(result[12] == "" || result[5] == " ") {
                        std::string temptype;
                        temptype += (std::string) result[2] + nameClass;
                        list_variable.emplace_back(temptype, result[4], "default");
                    } else {
                        list_variable.emplace_back(nameClass, result[4], result[12]);
                    }
                    if(countLocal > 0) {
                        size_t index = list_variable.size() - 1;
                        list_variable[index].SetLocal(true);
                        list_variable[index].SetXCord(currentXCord);
                        list_variable[index].SetYCord(currentYCord);
                    }
                    currentYCord += part.size() + 1;
                    continue;
                }
                countClassInit--;
            }
            return;
        }
     }

    for(auto i : list_struct) {

        std::string regex = "(\\s*)(";
        std::string nameStruct = i.GetName();

        regex += nameStruct + ")(\\s+)(.+)(\\;)(\\s*)";
        std::regex isInitClass(regex);

        if(std::regex_match(line.c_str(), result, isInitClass)) {
            String part;
            String temp = (std::string)result[4];
            String preSize = (std::string)result[1];
            preSize += result[2];
            preSize += result[3];
            currentYCord += preSize.size();
            while(!temp.empty()) {
                std::regex_match(temp.c_str(), result, partExpression);
                part = result[1];
                temp = result[7];
                countStructInit++;


                if (std::regex_match(part.c_str(), result, defInitClass)) {
                    String preSize = (std::string)result[1];
                    currentYCord += preSize.size();
                    if(result[5] == "" || result[5] == " ") {
                        list_variable.emplace_back(nameStruct, result[2], "default");
                    } else {
                        list_variable.emplace_back(nameStruct, result[2], result[5]);
                    }
                    if(countLocal > 0) {
                        size_t index = list_variable.size() - 1;
                        list_variable[index].SetLocal(true);
                        list_variable[index].SetXCord(currentXCord);
                        list_variable[index].SetYCord(currentYCord);
                    }
                    currentYCord += part.size() + 1;
                    continue;
                }

                if (std::regex_match(part.c_str(), result, emptyInitClass)) {
                    String preSize = (std::string)result[1];
                    currentYCord += preSize.size();
                    list_variable.emplace_back(nameStruct, result[2], "default");
                    if(countLocal > 0) {
                        size_t index = list_variable.size() - 1;
                        list_variable[index].SetLocal(true);
                        list_variable[index].SetXCord(currentXCord);
                        list_variable[index].SetYCord(currentYCord);
                    }
                    currentYCord += part.size() + 1;
                    continue;
                }
                if (std::regex_match(part.c_str(), result, refInitClass)) {
                    String preSize = (std::string)result[1];
                    currentYCord += preSize.size();
                    if(result[12] == "" || result[5] == " ") {
                        std::string temptype;
                        temptype += (std::string) result[2] + nameStruct;
                        list_variable.emplace_back(temptype, result[4], "default");
                    } else {
                        list_variable.emplace_back(nameStruct, result[4], result[12]);
                    }
                    if(countLocal > 0) {
                        size_t index = list_variable.size() - 1;
                        list_variable[index].SetLocal(true);
                        list_variable[index].SetXCord(currentXCord);
                        list_variable[index].SetYCord(currentYCord);
                    }
                    currentYCord += part.size() + 1;
                    continue;
                }
                countStructInit--;
            }
            return;
        }
     }
}

void MainWindow::UpdateModelVariables()
{
    QModelIndex index;
    size_t j = 0;
    model_variables->setRowCount(list_variable.size());
    for(auto i : list_variable) {
        String type = i.GetType();
        index = model_variables->index(j, 0);
        model_variables->setData(index, type.c_str());

        String name = i.GetName();
        index = model_variables->index(j, 1);
        model_variables->setData(index, name.c_str());

        String value = i.GetValue();
        index = model_variables->index(j, 2);
        model_variables->setData(index, value.c_str());

        if(i.GetLocal()) {
            String cord = "(" + std::to_string(i.GetXCord()) +
                    ", " + std::to_string(i.GetYCord()) + ")";

            index = model_variables->index(j, 3);
            model_variables->setData(index, cord.c_str());
        }
        j++;
    }
}

void MainWindow::UpdateModelPrototypes()
{
    QModelIndex index;
    size_t j = 0;
    model_prototypes->setRowCount(list_function.size());
    for(auto i : list_function) {
        String type = i.GetType();

        type += " " +  i.GetName() + " ("+ i.GetValue() + ");";
        qDebug()<<type.c_str();
        index = model_prototypes->index(j++, 0);
        model_prototypes->setData(index, type.c_str());
    }
}

void MainWindow::UpdateModelOverload()
{
    QModelIndex index;
    size_t j = 0;
    std::vector<String> usedVariable;

    for(auto i : list_function) {
        bool goFarther = false;


        for(auto o : list_function) {
            if(o.GetName() == i.GetName() && o.GetXCord() != i.GetXCord()) {
                goFarther = true;
                break;
            }
        }

        for(auto j : usedVariable) {
            if(j == i.GetName()) {
                goFarther = false;
                break;
            }
        }
        if(goFarther) {

            usedVariable.push_back(i.GetName());
            model_overload->setRowCount(j+1);
            String type = i.GetType() + " " + i.GetName() + " (" + i.GetValue() + ");";
            index = model_overload->index(j, 0);
            model_overload->setData(index, type.c_str());
            index = model_overload->index(j, 1);
            type = "";
            type += "(" + std::to_string(i.GetXCord()) + ", "
                                         + std::to_string(i.GetYCord()) + ")";
            model_overload->setData(index,type.c_str());
            j++;

            for(auto o : list_function) {
                if(o.GetName() == i.GetName() &&
                        (o.GetType() != i.GetType() || o.GetValue() != i.GetValue())) {
                    model_overload->setRowCount(j+1);
                    type = o.GetType() + " " + o.GetName() + " (" + o.GetValue() + ");";
                    index = model_overload->index(j, 0);
                    model_overload->setData(index, type.c_str());
                    index = model_overload->index(j, 1);
                    type = "";
                    type += "(" + std::to_string(o.GetXCord()) + ", "
                                                 + std::to_string(o.GetYCord()) + ")";
                    model_overload->setData(index, type.c_str());
                    j++;

                }
            }
        }


    }
}

void MainWindow::UpdateModelChangeVariable()
{
    QModelIndex index;
    size_t j = 0;
    model_change->setRowCount(list_changeVariable.size());
    for(auto i : list_changeVariable) {

        String type = i.GetName();
        index = model_change->index(j, 0);
        model_change->setData(index,type.c_str());

        type = "";
        type += "(" + QString::number(i.GetXCord()).toStdString() + ", " +
                QString::number(i.GetYCord()).toStdString() + ")";
        index = model_change->index(j, 1);
        model_change->setData(index,type.c_str());
        j++;
    }
}

void MainWindow::UpdateModelBranchingDepth()
{
    QModelIndex index;
    size_t j = 0;
    model_branchingDepth->setRowCount(list_branchingDepth.size());
    for(auto i : list_branchingDepth) {
        index = model_branchingDepth->index(j, 0);
        model_branchingDepth->setData(index, i);
        j++;
    }
}

void MainWindow::UpdateCountVariables()
{
    QString temp;
    QFont font = ui->label_array->font();
    font.setPointSize(12);

    temp = "Count arrays: " + QString::number(countArrayInit);
    ui->label_array->setText(temp);
    ui->label_array->setFont(font);

    temp = "Count structs: " + QString::number(countStructInit);
    ui->label_struct->setText(temp);
    ui->label_struct->setFont(font);

    temp = "Count classes: " + QString::number(countClassInit);
    ui->label_class->setText(temp);
    ui->label_class->setFont(font);
}


void MainWindow::on_pushButton_3_clicked()
{
    close();
}


void MainWindow::on_pushButton_2_clicked()
{
    filePath = QFileDialog::getOpenFileName(0, "Open File", "", "(*.cpp)");
    ReadFile();
}

void MainWindow::ReadFile()
{
    if(filePath == "") {
        return;
    }

    QFile file(filePath);
    if(!file.open(QFile::ReadOnly)) {
        QMessageBox::information(this, "Ошибка", "Файл не открыт");
        return;
    }
    QTextStream in(&file);
    isFile = true;
    text = in.readAll().toStdString();

    on_pushButton_clicked();
}
