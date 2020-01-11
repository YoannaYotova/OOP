#include "Entity.h"
#include"Point3D.h"
unsigned int Entity::newId = 23;


bool Entity::isAlive() const
{
	return true;
}

Entity::Entity():id(newId++),name(""),type(Type::Player)
{
	location = new Point2D;
}

Entity::Entity(const string & name, const Point2D & location, Type type) : id(newId++), name(name),type(type)
{
	this->location = location.clone();
}

Entity::Entity(const Entity & cpy):id(newId++),name(cpy.name),type(cpy.type)
{
	this->location = cpy.location->clone();
}

Entity & Entity::operator=(const Entity & cpy)
{
	if (this != &cpy)
	{
		name = cpy.name;
		type = cpy.type;
		delete location;
		location = cpy.location->clone();
	}
	return *this;
}


Entity::~Entity()
{
	delete location;
}

double Entity::getDistanceTo2D(const Entity & entity) const
{
	return location->Point2D::getDistanceTo(*entity.location);
}

double Entity::getDistanceTo(const Entity & entity) const
{
	Point3D* res = dynamic_cast<Point3D*>(location);
	Point3D* result = dynamic_cast<Point3D*>(entity.location);
	if (result == nullptr || res == nullptr) return location->getDistanceTo(*entity.location);
	return res->getDistanceTo(*result);
}

Point2D * Entity::moveTo(Point2D & point)
{
	if (dynamic_cast<Point3D*>(&point) != nullptr)
	{
		if (dynamic_cast<Point3D*>(this->location) != nullptr)
		{
			dynamic_cast<Point3D*>(this->location)->operator=(dynamic_cast<Point3D&>(point));
		}
		else
		{
			if (dynamic_cast<const Point2D* const>(this->location) != nullptr)
			{
				dynamic_cast<Point2D* const>(this->location)->operator=(dynamic_cast<const Point2D&>(point));
			}
		}
	}
	else
	{

		if (dynamic_cast<Point2D*>(&point) != nullptr)
		{
			if (dynamic_cast<Point3D*>(this->location) != nullptr)
			{
				Point3D* newPoint = new Point3D;

				newPoint->Point2D::operator=(point);

				dynamic_cast<Point3D*>(this->location)->operator=(dynamic_cast<Point3D&>(*newPoint));

				delete newPoint;
			}
			else
			{
				if (dynamic_cast<const Point2D* const>(this->location) != nullptr)
				{
					dynamic_cast<Point2D* const>(this->location)->operator=(dynamic_cast<const Point2D&>(point));
				}
			}
		}
	}
}
