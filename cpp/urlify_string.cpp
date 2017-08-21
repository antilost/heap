/*
    Написать метод, который заменит все пробелы в строке на  "%20" inplace.
    На вход подается строка с зарезервированными под расширение символами
    (гарантируется, что  resize до разумных размеров не будет аллоцировать память).

    Ограничения:
     * O(1) по памяти.
     * O(N) по времени.
*/

#include <iostream>
#include <string>
#include <cassert>

void urlify(std::string& s);

int main(void) {
    std::string s0 = "my u  rl ";

    std::cout << s0 << std::endl;
    urlify(s0);
    std::cout << s0 << std::endl;
    assert(s0 == "my%20u%20%20rl%20");

    return 0;
}

void urlify(std::string& s) {
    int spaces_count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            spaces_count++;
        }
    }

    int original_size = s.size();
    s.resize(s.size() + spaces_count * 2, 'X');

    int i = original_size - 1;
    int j = s.size() - 1;
    while (i >= 0) {
        if (s[i] == ' ') {
            s[j] = '0'; j--;
            s[j] = '2'; j--;
            s[j] = '%'; j--;
            i--;
        } else {
            s[j] = s[i];
            i--; j--;
        }
    }
}
