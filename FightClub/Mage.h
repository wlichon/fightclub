#pragma once
#include "Character.h"

class Character;

class Mage : public Character{
public:
	Mage(bool ai);
	bool attack(Character& target) override;
	bool takeDamage(int dmg) override;
	bool fireball(Character& target);
	bool recharge();
	bool printInfo() override;
	static int getWins();
	static int getLosses();
	~Mage();
	
private:
	static int wins;
	static int losses;
	static int typeCount;
	static int botCount;
protected:
	int _mana;
	int _magic;
};

