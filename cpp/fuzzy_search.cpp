/*
 * https://femida.yandex-team.ru/problems/2203
 *
 * Функция fuzzysearch ищет строку pattern в строке str
 * Возвращает:
 *  - true, если pattern является подпоследовательностью внутри str, не обязательно непрерывной
 *  - false, иначе
 */

#include <iostream>
#include <string>

using namespace std;

bool fuzzysearch(string pattern, string str);

int main(void) {
	cout << fuzzysearch("car", "cartwheel") << endl;        // true
    cout << fuzzysearch("cwhl", "cartwheel") << endl;       // true
    cout << fuzzysearch("cwheel", "cartwheel") << endl;     // true
    cout << fuzzysearch("cartwheel", "cartwheel") << endl;  // true
    cout << fuzzysearch("wee", "cartwheel") << endl;        // false
    cout << fuzzysearch("cwheeel", "cartwheel") << endl;    // false
    cout << fuzzysearch("lw", "cartwheel") << endl;         // false

	return 0;
}

bool fuzzysearch(string pattern, string str) {
	bool result = false;

	int i = 0, j = 0;
	while (str[i] && pattern[j]) {
		if (pattern[j] && str[i] == pattern[j]) {
			j++;
		}
		i++;
	}
	
	if (!pattern[j]) {
		result = true;
	}

	return result;
}
