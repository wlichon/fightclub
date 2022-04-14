#pragma once
#include "Character.h"

class Character;

class Knight : public Character{
public:
	Knight(bool ai);
	bool recharge();
	bool attack(Character& target) override;
	bool takeDamage(int dmg) override;
	bool printInfo() override;
	static int getWins();
	static int getLosses();
	~Knight();


private:
	static int wins;
	static int losses;
	static int typeCount;
	static int botCount;


protected:
	int _armor;
};

