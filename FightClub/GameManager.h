#pragma once
#include "Character.h"
#include "Team.h"


class GameManager{
public:
	GameManager();
	bool selectMode();
	bool makeTeams();
	bool one_vs_one(Character& a, Character& b);
	bool team_vs_team(Team& a, Team& b);
	bool round(Character& a, Character& b);
	int speedOff(Character& a, Character& b);
	
	bool creationInterface();
	Character* createMage(bool ai);
	Character* createKnight(bool ai);

private:
	int _round;
	bool _gameOver;
};

