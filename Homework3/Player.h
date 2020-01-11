#pragma once
#include"Entity.h"
class Player: public Entity
{
	int damage;
	int health;


public:
	Player();
	~Player();

	bool isAlive() const;
};

