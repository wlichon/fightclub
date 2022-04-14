#include "Character.h"
#include "Team.h"

int Character::wins = 0;
int Character::losses = 0;

Character::~Character() {
	//test
}

Character::Character(int hp, int atk, int agility) {
	_hp = hp;
	_atk = atk;
	_agility = agility;
	_name = "Character";
	_player = "dummy";
}

int Character::getWins() {
	return wins;
}

int Character::getLosses() {
	return losses;
}


Character::Character(int hp, int atk,int agility,bool ai,char team) {
	_hp = hp;
	_atk = atk;
	_agility = agility;
	_ai = ai;
	_team = team;
}

int Character::getHP() {
	return _hp;
}

bool Character::selectEnemy(Team& a) {
	int option;
	Character* target = NULL;

	if (this->getAI() == false) {
		std::cout << "Your stats: " << std::endl;
		this->printInfo();

		printf("\n");
		
		a.printTeam();

		do {
			std::cout << "Which Playernumber do you wish to attack?: " << std::endl;
			std::cin >> option;
		} while (option <= 0);
		if (option <= a.getPlayerCount()) {
			target = a.getPlayer(option - 1);
			if (target->getHP() == 0) {
				std::cout << "Target is already dead!" << std::endl;
				return false;
			}
			return this->attack(*target);
		}
	}

	else {
		int coinflip = rand() % 2;
		if (coinflip) {
			int randomIndex;
			do {
				randomIndex = rand() % a.getPlayerCount();
				target = a.getPlayer(randomIndex);
			} while (target->getHP() == 0);
			return this->attack(*target);
		}
		else {
			return this->recharge();
		}


	}
	return false;

}



bool Character::getAI() {
	return this->_ai;
}

bool Character::recharge() {
	std::cout << "recharging character";
	return true;

}

int Character::getAgility() {
	return this->_agility;
}

std::string Character::getName() {
	return _name;
}

Character::Character() {
	_hp = 10;
	_atk = 5;
	_agility = 5;
	_ai = true;
	_team = 'B';
}

bool Character::attack(Character& target) {
	std::cout << "Character attacks" << std::endl;
	return target.takeDamage(_atk);
}

bool Character::printInfo() {
	std::cout << "Character info" << std::endl;
	return true;
}


bool Character::takeDamage(int dmg) {
	std::cout << "Character takes a hit" << std::endl;
	_hp -= dmg;
	if (_hp <= 0) {
		_hp = 0;
		std::cout << "Character is dead" << std::endl;
		return true;
	}

	std::cout << "Characters HP: " << _hp << std::endl;
	return false;
}
