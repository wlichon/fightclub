#define _CRTDBG_MAP_ALLOC
#include "common.h"
#include <crtdbg.h>
#include <vector>

int main() {
	GameManager game;

	std::vector<int>a(10);

	char option;

	do {
		game.selectMode();
		std::cout << "Would you like to play another game?: (Y/N)" << std::endl;
		std::cin >> option;
	} while (option == 'Y');
	_CrtDumpMemoryLeaks();

	return 0;
}