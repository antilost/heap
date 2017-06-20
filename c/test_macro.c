// Tutorial
// http://www.opennet.ru/docs/RUS/cpp/cpp-5.html

// Простой макрос: сокращение
#define EXIT_CODE_NORMAL 0

// Макросы с аргументами
#define max(A, B) ( (A) > (B) ? (A) : (B) )
#define min(A, B) ( (A) < (B) ? (A) : (B) )

// Макрос с аргументом X, возвращает -1/X
// Если есть аргументы, то скобка ( должна идти сразу после имени макроса)
#define FOO(X) - 1 / (X)

// Макрос без аргументов, возвращает всегда константное значение (X) - 1/(X)
#define X 10
#define BAR (X) - 1.0 / (X)

// Стандартные макросы
// __LINE__
// __FILE__
// __DATE__ строковая константа, дата запуска препроцессора
// __TIME__ строковая константа, время запуска препроцессора

#include "stdio.h"
int main(void) {
	int m;
	m = max(3, 4);
	printf("Max 3, 4: %d\n", m);

	int *p, k;
	k = 5;
	p = &k;
	k = 8;
	m = max(k, *p);
	printf("Max k, *p: %d\n", m);
	
	m = min( max(2,3), 10);
	printf("min( max(2,3), 10): %d\n", m);
	
	printf("%.2f\n", FOO(2.0)); // -0.50

	printf("%.2f\n", BAR); // 9.90
	
	// Стандартные макросы
	printf("FILE: %s\n", __FILE__);
	printf("LINE: %d\n", __LINE__);
	
	#line 999 "file.txt"
	printf("FILE: %s\n", __FILE__);
	printf("LINE: %d\n", __LINE__);

	printf("FILE: %s\n", __FILE__);
	printf("LINE: %d\n", __LINE__);

	char *s = (char*)__TIME__;
	printf("preprocessor run at %s %s\n", __DATE__, s);
	
	return EXIT_CODE_NORMAL;
}
