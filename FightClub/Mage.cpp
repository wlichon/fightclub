#include "Mage.h"

int Mage::wins = 0;
int Mage::losses = 0;
int Mage::typeCount = 0;
int Mage::botCount = 0;

Mage::Mage(bool ai) : Character(15, 1, 4) {
	this->_mana = 10;
	this->_magic = 8;
	this->_ai = ai;
	this->_name = "Mage";
	if (ai) {
		this->_player = "Bot";
		std::string temp(_player + std::to_string(++botCount));
		_player = temp;
	}
	else {
		std::cout << "Name your Character: " << std::endl;
		std::cin >> _player;
		std::string temp(_player + std::to_string(++typeCount));
		_player = temp;
	}
}

Mage::~Mage() {
	//test
}

int Mage::getWins() {
	return wins;
}

int Mage::getLosses() {
	return losses;
}

bool Mage::attack(Character& target) {
	bool win = false;
	if (_mana >= 5) {
		win = fireball(target);
		if (win) {
			wins++;
			return true;
		}
		return false;
	}
	std::cout << "Mage attacks" << std::endl;
	win = target.takeDamage(_atk);
	if (win) {
		wins++;
		return true;
	}
	return false;
}

bool Mage::fireball(Character& target) {
	_mana -= 5;
	std::cout << "Mage casts fireball" << std::endl;
	return target.takeDamage(_magic);
	
}

bool Mage::printInfo() {
	std::cout << "MAGE: ("<< _player << ") HP: " << _hp << " Mana: " << _mana << std::endl;
	return true;
}

bool Mage::recharge() {
	std::cout << "Mage meditates and regains Mana" << std::endl;
	_mana += 10;
	return false;
}

bool Mage::takeDamage(int dmg) {
	std::cout << "Mage takes a hit" << std::endl;
	_hp -= dmg;
	if (_hp <= 0) {
		_hp = 0;
		std::cout << "Mage is dead" << std::endl;
		losses++;
		return true;
	}

	std::cout << "Mage HP: " << _hp << std::endl;
	return false;
}