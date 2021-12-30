#include <iostream>
using namespace std;

void ten_forte(double val) {
    int del = val, wh, rem;

    del = val / 12;
    wh = del * 12;
    rem = val - wh;

    if (del == 0) {
        if (rem == 10)
            cout << 'a';
        if (rem == 11)
            cout << 'b';
        if (rem < 10)
            cout << rem;
        return;
    }
    
   ten_forte(val /= 12);

    
        if (rem == 10)
            cout << 'a';
        if (rem == 11)
            cout << 'b';
        if (rem < 10)
            cout << rem;
       
    
    
}

int main() {
    double num;
    cin >> num;

   
    double drob = num - trunc(num);
    double per = drob * 1e5;
    int value = per;

    int save_value = value;
    int v_col=0;
    while (save_value > 1) {
        v_col++;
        save_value /= 10;
    }

    double save_num = num;
    int len_mant = 0;
    while (save_num > 1) {
        len_mant++;
        save_num /= 10;
    }
    int s = 0;
    int v = 0;

    while (num >= 1) {
        s += ((int)num % 10) * pow(7, v);
        num = trunc(num / 10);
        v++;

    }
    ten_forte(s);
    cout << '.';
    //теперь для дробной части перевод
    double sum = 0;
    while (value >= 1) {
        sum += (value % 10) * pow(7, -v_col);
        value = trunc(value / 10);
       v_col--;

    }
   
    //нашел сум в десятичной теперь нужно 10-12
    
    double save_sum = sum;
    for (int i = 0; i < 6; i++) {

        double a = sum;
        save_sum = a;
        save_sum *= 12;
        a = save_sum - trunc(save_sum);



        //gh[i] = drob_save;

        if (trunc(save_sum) == 10) {
            cout << "a";
        }
        else if (trunc(save_sum) == 11) {
            cout << "b";
        }
        else {
            cout << trunc(save_sum);
        }

        sum = a;
    }
    
}
   
