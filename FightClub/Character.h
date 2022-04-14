#pragma once
#include "Character.h"
#include <iostream>
#include <cstdlib>
#include <sstream>


class Team;

class Character{
public:
	Character();
	Character(int hp, int atk, int agility);
	Character(int hp,int atk,int agility,bool ai,char team);
	virtual bool attack(Character& target);
	virtual bool recharge();
	virtual bool takeDamage(int dmg);
	virtual bool printInfo();
	int getAgility();
	bool getAI();
	static int getWins();
	static int getLosses();
	std::string getName();
	bool selectEnemy(Team& a);
	int getHP();
	virtual ~Character();

private:
	static int wins;
	static int losses;
	static int typeCount;


protected:
	int _hp;
	int _atk;
	int _agility;
	bool _ai;
	char _team;
	std::string _player;
	std::string _name;
};

