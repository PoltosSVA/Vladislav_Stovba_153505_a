//
// pch.cpp
//

#include "pch.h"
char* arab2roman(int ar, const char** rom, int* arabik) {
    char roman[80];
    int m = 12, arabmax_el = arabik[m];
    char romanmax_el = rom[m][0];
    int i, n;
    if (!ar) {
        return 0;
    }
    i = 0;
    while (ar > arabmax_el) {
        roman[i++] = romanmax_el;
        ar -= arabmax_el;
    }
    n = m;
    while (ar > 0) {
        if (ar >= arabik[n]) {
            roman[i++] = rom[n][0];
            if (n % 2 == 1)
                roman[i++] = rom[n][1];
            ar -= arabik[n];
        }
        else
            n--;
    }
    roman[i] = '\0';
    //cout << roman;
}
