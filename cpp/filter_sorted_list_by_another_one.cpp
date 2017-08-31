/*
 * https://femida.yandex-team.ru/problems/3406
 *
 * Модификация задачи на слияние 2х списков.
 * Есть 2 сортированных последовательности целых чисел.
 * Хотим напечатать те элементы из первой последовательности, которых нет во второй последовательности.
 * Элементы могут повторяться. Сделать без накопления в памяти.
 * 
 * Test input:
9
3
1 2 2 2 5 9 10 10 12
-1 2 10
 */

using namespace std;

#include <iostream>
#include <vector>

int main(void) {
    int a_size, b_size;
    cin >> a_size >> b_size;

    vector<int> a(a_size);
    vector<int> b(b_size);

    while (a_size--) {
        int v;
        cin >> v;
        a.push_back(v);
    }
    while (b_size--) {
        int v;
        cin >> v;
        b.push_back(v);
    }

    int i = 0;
    int j = 0;
    while (i < a.size()) {
        bool do_print = true;
        if (j < b.size()) {
            while (b[j] < a[i]) {
                j++;
            }
            if (a[i] == b[j]) {
                do_print = false;
            }
        }

        if (do_print) {
            cout << a[i] << " ";
        }
        i++;
    }
    cout << endl;

    return 0;
}
