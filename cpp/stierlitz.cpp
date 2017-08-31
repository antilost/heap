/*
 * К исходной строке применили 3 преобразования:
 * 1. удалили все пробелы и знаки препинания
 * 2. все подряд идущие одинаковые буквы заменили одной такой буквой
 * 3. в произвольные места вставили удвоенные буквы произвольное количество раз
 */

#include <iostream>

using namespace std;

int main(void) {
    string s = "wwstdaadierfflitzzmjjrtypozllzopytrffmz"; // stierlitz
    cout << s << endl;
    
    int write_to;
    for (int i = 0; i < s.size(); i++) {
        char now = s[i];
        if (write_to == 0 || now != s[write_to - 1]) {
            s[write_to] = now;
            write_to++;
        } else if (write_to > 0 && s[write_to - 1] == now) {
            write_to--;
        }
    }
    s.resize(write_to);

    cout << s << endl;

    return 0;    
}
