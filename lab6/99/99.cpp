#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;
int main() {
    string str;
    getline(cin, str);
    int n = str.size();
    double Sum = 0;
    for (int i = 0; i < n; i++) {
        if (((int)str[i] >= 48) && ((int)str[i] <= 57)) {
            int col = 0;
            int j = i;
            int p_1 = 0;
            int p_2 = 0;
            while (((int)str[j] >= 48) && ((int)str[j] <= 57) || str[j] == ',' || (str[j] == '.' && str[j + 1] >= 48 && str[j + 1] <= 57) || (str[j] == '.' && str[j - 1] >= 48 && str[j + 1] <= 57) || str[j] == 'e' || str[j] == 'E' || str[j] == '+' || str[j] == '-') {
                if (str[j] == '.' || str[j] == ',') {
                    p_1 = j;
                }

                if ((str[j] == 'e' || str[j] == 'E') && (str[j + 1] == '+' || str[j + 1] == '-' || ((int)str[j + 1] >= 48 && (int)str[j + 1] <= 57))) {// число e
                    p_2 = j;
                }

                col++;
                j++;
            }

            double numb = 0;

            if (p_1 == 0 && p_2 != 0) {//рассмотрим e
                if (str[p_2 + 1] == '+') {
                    int k = 0;
                    j -= 1;

                    double degree = 0;
                    for (j; j > p_2 + 1; j--) {//считаем число в степени
                        degree += (str[j] - 48) * pow(10, k);
                        k++;
                    }

                    k = 0;
                    j -= 2;
                    double man = 0;
                    for (j; j >= i; j--) {
                        man += (str[j] - 48) * pow(10, k);
                        k++;
                    }

                    numb = man * pow(10, degree);//число e с +
                }
                else if (str[p_2 + 1] == '-') {
                    int k = 0;
                    j -= 1;

                    double degree = 0;
                    for (j; j > p_2 + 1; j--) {
                        degree += (str[j] - 48) * pow(10, k);
                        k++;
                    }

                    k = 0;
                    j -= 2;
                    double man = 0;
                    for (j; j >= i; j--) {
                        man += (str[j] - 48) * pow(10, k);
                        k++;
                    }

                    numb = man * pow(10, -degree);//число e с -
                }
                else {
                    int k = 0;
                    j -= 1;

                    double degree = 0;
                    for (j; j > p_2; j--) {
                        degree += (str[j] - 48) * pow(10, k);
                        k++;
                    }

                    k = 0;
                    j -= 1;
                    double man = 0;
                    for (j; j >= i; j--) {
                        man += (str[j] - 48) * pow(10, k);
                        k++;
                    }

                    numb = man * pow(10, degree);//число e
                }
            }
            else if (p_1 != 0 && p_2 == 0) {//рассмотрим дробное число
                int k = 0;
                j -= 1;
                for (j; j > p_1; j--) {
                    numb += (str[j] - 48) * pow(10, k);//целая часть дробного числа
                    k++;
                }

                double drob = 0;//дробная часть
                drob = numb * pow(10, -k);

                numb = 0;
                j -= 1;
                k = 0;
                for (j; j >= i; j--) {
                    numb += (str[j] - 48) * pow(10, k);
                    k++;
                }

                numb += drob;// полное дробное число
            }
            else if (p_1 != 0 && p_2 != 0) {//дробное и  e
                if (str[p_2 + 1] == '+') {
                    int k = 0;
                    j -= 1;

                    double degree = 0;
                    for (j; j > p_2 + 1; j--) {
                        degree += (str[j] - 48) * pow(10, k);
                        k++;
                    }

                    k = 0;
                    j -= 2;

                    double man = 0;
                    for (j; j > p_1; j--) {
                        man += (str[j] - 48) * pow(10, k);
                        k++;
                    }

                    double drob = 0;
                    drob = man * pow(10, -k);

                    man = 0;
                    j -= 1;
                    k = 0;
                    for (j; j >= i; j--) {
                        man += (str[j] - 48) * pow(10, k);
                        k++;
                    }

                    man += drob;

                    numb = man * pow(10, degree);
                }
                else if (str[p_2 + 1] == '-') {
                    int k = 0;
                    j -= 1;

                    double degree = 0;
                    for (j; j > p_2 + 1; j--) {
                        degree += (str[j] - 48) * pow(10, k);
                        k++;
                    }

                    k = 0;
                    j -= 2;

                    double man = 0;
                    for (j; j > p_1; j--) {
                        man += (str[j] - 48) * pow(10, k);
                        k++;
                    }

                    double drob = 0;
                    drob = man * pow(10, -k);

                    man = 0;
                    j -= 1;
                    k = 0;
                    for (j; j >= i; j--) {
                        man += (str[j] - 48) * pow(10, k);
                        k++;
                    }

                    man += drob;

                    numb = man * pow(10, -degree);
                }
                else {
                    int k = 0;
                    j -= 1;

                    double degree = 0;
                    for (j; j > p_2; j--) {
                        degree += (str[j] - 48) * pow(10, k);
                        k++;
                    }

                    k = 0;
                    j -= 1;

                    double man = 0;
                    for (j; j > p_1; j--) {
                        man += (str[j] - 48) * pow(10, k);
                        k++;
                    }

                    double drob = 0;
                    drob = man * pow(10, -k);

                    man = 0;
                    j -= 1;
                    k = 0;
                    for (j; j >= i; j--) {
                        man += (str[j] - 48) * pow(10, k);
                        k++;
                    }

                    man += drob;

                    numb = man * pow(10, degree);
                }
            }
            else {
                int k = 0;
                j -= 1;
                for (j; j >= i; j--) {
                    numb += (str[j] - 48) * pow(10, k);
                    k++;
                }
            }

            if (i != 0 && str[i - 1] == '-') {//отрицательное 
                numb *= (-1);
            }

            Sum += numb;
            i += col;
        }
    }
    cout << "Sum= " <<setprecision(14)<< Sum << endl;
    return 0;
}