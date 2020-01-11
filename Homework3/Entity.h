#pragma once
#include"Point2D.h"
#include<string>
using namespace std;

enum class Type {

	Player,NPC,Mob
};

class Entity
{
	unsigned int id;
	string name;
	static unsigned int newId;
	Point2D* location;
	Type type;

public:
	virtual bool isAlive() const;
	Entity();
	Entity(const string& name, const Point2D& location, Type type);
	Entity(const Entity& cpy);
	Entity& operator=(const Entity& cpy);
	~Entity();

	double getDistanceTo2D(const Entity& entity)const;
	double getDistanceTo(const Entity& entity)const;
	Point2D* moveTo(Point2D& point);
};


