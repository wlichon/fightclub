#include "GameManager.h"
#include "Mage.h"
#include "Knight.h"


GameManager::GameManager() {
	this->_round = 0;
	this->_gameOver = false;
}

bool GameManager::one_vs_one(Character& a, Character& b) {
	if (speedOff(a, b) < 0) {
		return round(b, a);
	}
	
	else if (speedOff(a, b) == 0) {
		int coinflip = rand() % 2;
		if (coinflip) {
			return round(a, b);
		}
		else {
			return round(b, a);
		}
	}
	
	else {
		return round(a, b);
	}
}

bool GameManager::selectMode() {
	char option;
	std::cout << "1v1 Game (A)\n" << "Team Game (B)\n";
	std::cin >> option;
	if (option == 'A') {
		creationInterface();
	}
	else if (option == 'B') {
		makeTeams();
	}
	else {
		return true;
	}
	return false;
}

bool GameManager::makeTeams() {
	Team a("Alpha");
	Team b("Beta");


	a.sortSpeed();
	b.sortSpeed();

	//a.printTeam();
	//b.printTeam();

	bool result;

	result = team_vs_team(a,b);

	if (result) {
		std::cout << "Team Beta Wins!" << std::endl;
	}
	else {
		std::cout << "Team Alpha Wins!" << std::endl;
	}

	return false;
}

bool GameManager::team_vs_team(Team& a,Team& b) {
	int priorityIndex1 = 0;
	int priorityIndex2 = 0;
	int killCount1 = 0;
	int killCount2 = 0;

	bool deathFlag = false;

	int round = 1;
	char option;

	Character* p1;
	Character* p2;
	while (true) {
		printf("-------------------------------------------------\n");
		std::cout << "Round: " << round << std::endl;

		do {
			if (priorityIndex1 != a.getPlayerCount()) {
				p1 = a.getPlayer(priorityIndex1++);
				if (p1 != NULL && p1->getHP() != 0) {
					if (p1->getAI() == false) {

						std::cout << "Attack or Recharge? (A/R)" << std::endl;
						std::cin >> option;
						if (option == 'A') {
							deathFlag = p1->selectEnemy(b);
						}
						else {
							p1->recharge();
						}
					}
					else {
						deathFlag = p1->selectEnemy(b);
					}

					if (deathFlag) {
						killCount1++;
						if (killCount1 == b.getPlayerCount()) {
							Mage u(true);
							Knight v(true);

							std::cout << u.getName() << " wins: " << u.getWins() << " losses: " << u.getLosses() << std::endl;
							std::cout << v.getName() << " wins: " << v.getWins() << " losses: " << v.getLosses() << std::endl;
							
							return false;    //if false then team a wins
						}
						deathFlag = false;
					}
				}
			
			
			}
			if (priorityIndex2 != b.getPlayerCount()) {
				p2 = b.getPlayer(priorityIndex2++);
				if (p2 != NULL && p2->getHP() != 0) {
					if (p2->getAI() == false) {
						std::cout << "Attack or Recharge? (A/R)" << std::endl;
						std::cin >> option;
						if (option == 'A') {
							deathFlag = p2->selectEnemy(a);
						}
						else {
							p2->recharge();
						}
					}
					else {
						deathFlag = p2->selectEnemy(a);
					}

					if (deathFlag) {
						killCount2++;
						if (killCount2 == a.getPlayerCount()) {
							Mage u(true);
							Knight v(true);

							std::cout << u.getName() << " wins: " << u.getWins() << " losses: " << u.getLosses() << std::endl;
							std::cout << v.getName() << " wins: " << v.getWins() << " losses: " << v.getLosses() << std::endl;

							return true; //if true then team b wins
						}
						deathFlag = false;
					}
				}
			}
		} while (priorityIndex1 != a.getPlayerCount() || priorityIndex2 != b.getPlayerCount());
		
		priorityIndex1 = 0;
		priorityIndex2 = 0;
		round++;
		printf("-------------------------------------------------\n");
	}
	//return false;
}

bool GameManager::creationInterface() {
	int i = 0;
	Character* a = NULL;
	Character* b = NULL;
	do {
		std::cout << "Mage (M) , Knight (K)\n";
		(i == 0) ? std::cout << "Player 1: " << std::endl : std::cout << "Player 2: " << std::endl;
		char option;
		std::cin >> option;
		std::cout << "Controlled by AI? (Y/N)\n";
		char option2;
		std::cin >> option2;
		bool ai;
		if (option2 == 'Y') {
			ai = true;
		}
		else {
			ai = false;
		}
		switch (option) {
		case 'M':
			((i == 0) ? a : b) = createMage(ai);
			break;
		case 'K':
			((i == 0) ? a : b) = createKnight(ai);
			break;
		default:
			return true;

		}
		i++;
	} while (i < 2);


	bool condition = false;
	do {
		condition = one_vs_one(*a, *b);
	} while (!condition);

	Mage u(true);
	Knight v(true);

	std::cout << u.getName() << " wins: " << u.getWins() << " losses: " << u.getLosses() << std::endl;
	std::cout << v.getName() << " wins: " << v.getWins() << " losses: " << v.getLosses() << std::endl;

	delete a;
	delete b;



	return false;
}

Character* GameManager::createMage(bool ai) {
	Mage* a = new Mage(ai);
    return a;
}

Character* GameManager::createKnight(bool ai) {
	Knight* a = new Knight(ai);
	return a;
}

bool GameManager::round(Character& a, Character& b) {
	char option = 'n';
	printf("-------------------------------------------------\n");

	std::cout << "Round Number: " << _round << std::endl << std::endl;

	a.printInfo();
	b.printInfo();

	printf("\n");
	
	if (a.getAI() == false) {
		while (option != 'A' && option != 'B') {
			std::cout << "Attack (A),Recharge (B)\n";
			std::cin >> option;
		}
		if (option == 'A') {
			if (a.attack(b)) // falls return == true dann ist der Spieler b tot.
				return true;
		}
		else if (option == 'B') {
			a.recharge();
		}
	}
	else {
		int coinflip = rand() % 2;
		if (coinflip) {
			if (a.attack(b))
				return true;
		}
		else {
			a.recharge();
		}
	}
	option = 'n';

	if (b.getAI() == false) {
		while (option != 'A' && option != 'B') {
			std::cout << "Attack (A),Recharge (B)\n";
			std::cin >> option;
		}
		if (option == 'A') {
			if (b.attack(a))
				return true;
		}
		else if (option == 'B') {
			b.recharge();
		}
	}
	else {
		int coinflip = rand() % 2;
		if (coinflip) {
			if (b.attack(a))
				return true;
		}
		else {
			b.recharge();
		}
	}

	_round++;

	printf("-------------------------------------------------\n");

	printf("\n");

	return false;

}

int GameManager::speedOff(Character& a, Character& b) {
	int diff = a.getAgility() - b.getAgility();
	return diff;
}