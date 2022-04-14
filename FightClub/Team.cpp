#include "Team.h"

Team::Team(std::string name) {
	Character* a;
	_playerCount = 0;
	_name = name;

	for (int i = 0; i < MAX_PLAYERS; i++) {
		players[i] = NULL;
	}

	bool addMore = true;

	std::cout << "Team: " << _name << std::endl;

	while (addMore) {
		char option;
		std::cout << "Add Mage or Knight? (M/K)" << std::endl;
		std::cin >> option;
		std::cout << "Controlled by AI? (Y/N)" << std::endl;
		char option2;
		std::cin >> option2;
		bool ai = false;

		if (option2 == 'Y') {
			ai = true;
		}
		else {
			ai = false;
		}
		if (option == 'M') {
			a = new Mage(ai);
		}
		else if (option == 'K') {
			a = new Knight(ai);
		}
		else {
			break;
		}
		players[_playerCount++] = a;


		if (_playerCount == MAX_PLAYERS) {
			addMore = false;
		}
		else {
			std::cout << "Add more Players?: (Y/N)" << std::endl;
			std::cin >> option2;
			if (option2 == 'N') {
				addMore = false;
			}
		}

	}

}

Team::~Team() {
	for (int i = 0; i < MAX_PLAYERS; i++) {
		if (players[i] != NULL) {
			delete players[i];
		}
	}
}


int Team::getPlayerCount() {
	return _playerCount;
}

Character* Team::getPlayer(int index) {
	return players[index];
}


bool Team::sortSpeed() {
	for (int i = 0; i < _playerCount; i++) {
		for (int j = 0; j < _playerCount-1; j++) {
			if (players[j]->getAgility() < players[j + 1]->getAgility()) {
				Character* temp = players[j];
				players[j] = players[j + 1];
				players[j + 1] = temp;
			}
		}
	}
	return false;
}

void Team::printTeam() {
	std::cout << "Team: " << _name << " Players" << std::endl;
	for (int i = 0; i < _playerCount; i++) {
		std::cout << "Number " << i + 1 << ": ";
		players[i]->printInfo();
		printf("\n");
	}
}
