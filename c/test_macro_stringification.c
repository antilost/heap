// Tutorial
// http://www.opennet.ru/docs/RUS/cpp/cpp-5.html

#include "stdio.h"

// Стрингификация
typedef struct command {
	char* name;
	void (*proc)();
};

void help_proc() {
	printf("Help yourself!\n");
	return;
}

void quit_proc() {
	return;
}

void create_proc() {
	return;
}

#define COMMAND(NAME) { #NAME, NAME ## _proc }

int main(void) {
	struct command commands[] = {
		COMMAND(help),
		COMMAND(quit),
		"create", create_proc
	};

	commands[0].proc();
	printf("Done\n");

	return 0;
}
