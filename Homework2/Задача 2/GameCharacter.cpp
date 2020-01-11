#include "GameCharacter.h"
#include<cstring>


GameCharacter::GameCharacter(): HP(0),AP(0),MP(0),DP(0)
{
	setName("");
}

GameCharacter::GameCharacter(const char * name, int hp, int ap,int mp, int dp):
	HP(hp),AP(ap),MP(mp),DP(dp)
{
	setName(name);
}

GameCharacter::GameCharacter(const GameCharacter & cpy):
	HP(cpy.HP),AP(cpy.AP),MP(cpy.MP),DP(cpy.DP)
{
	setName(cpy.name);
}

GameCharacter & GameCharacter::operator=(const GameCharacter & cpy)
{
	if (this != &cpy)
	{
		delete[] name;
		HP=cpy.HP;
		AP = cpy.AP;
		MP = cpy.MP;
		DP = cpy.DP;
		setName(cpy.name);

	}
	return*this;
}


void GameCharacter::setName(const char * name)
{
	int lenght = strlen(name) + 1;
	char* tmp = new char[lenght];
	strcpy_s(tmp, lenght, name);
	delete[] this->name;
	this->name = tmp;
}

void GameCharacter::getattacked(int pointsOfOpponent)
{
	int difference = pointsOfOpponent - DP;
	if (difference > 0)HP -= difference;
}

GameCharacter::~GameCharacter()
{
	delete[] name;
}
