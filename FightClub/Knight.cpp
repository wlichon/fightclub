#include "Knight.h"

int Knight::wins = 0;
int Knight::losses = 0;
int Knight::typeCount = 0;
int Knight::botCount = 0;

Knight::Knight(bool ai) : Character(20,5,2) {
	_armor = 4;
	_ai = ai;
	this->_name = "Knight";
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

Knight::~Knight() {
	//test
}

int Knight::getWins() {
	return wins;
}

int Knight::getLosses() {
	return losses;
}


bool Knight::recharge() {
	std::cout << "Knight replaces his old armor" << std::endl;
	_armor = 4;
	return false;
}

bool Knight::printInfo() {
	std::cout << "KNIGHT: (" << _player << ") HP: " << _hp << " Armor: " << _armor << std::endl;
	return true;
}

bool Knight::attack(Character& target) {
	std::cout << "Knight attacks" << std::endl;
	bool win = false;
	win = target.takeDamage(_atk);
	if (win) {
		wins++;
		return true;
	}
	return false;
}

bool Knight::takeDamage(int dmg) {
	std::cout << "Knight takes a hit" << std::endl;
	if (_armor <= dmg) {
		_hp -=  dmg-_armor;
		_armor = 0;
		if (_hp <= 0) {
			_hp = 0;
			std::cout << "Knight is dead" << std::endl;
			losses++;
			return true;
		}
	}
	_armor /= 2;
	std::cout << "Knights HP: " << _hp << std::endl;
	return false;
}