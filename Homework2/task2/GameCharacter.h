#pragma once
class GameCharacter
{
protected:
	char* name = nullptr;
	int HP;
	int MP;
	int AP;
	int DP;
public:
	GameCharacter();
	GameCharacter(const char* name, int hp, int ap,int mp, int dp);
	GameCharacter(const GameCharacter& cpy);
	GameCharacter& operator=(const GameCharacter& cpy);
	void setName(const char* name);
	void getattacked(int);
	virtual ~GameCharacter() = 0;
};

