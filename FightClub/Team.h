#pragma once
#include <iostream>
#include "Character.h"
#include "Mage.h"
#include "Knight.h"

#define MAX_PLAYERS 3

class Team{
public:
	Team(std::string name);
	bool sortSpeed();
	void printTeam();
	Character* getPlayer(int index);
	int getPlayerCount();
	~Team();

private:
	Character* players[MAX_PLAYERS];
	int _playerCount;
	std::string _name;

};

