#include "Point2D.h"

#include<math.h>

Point2D::Point2D():x(0),y(0)
{
}

Point2D::Point2D(double x, double y)
{
	this->x = x;
	this->y = y;
}

double Point2D::getDistanceTo(const Point2D & point) const
{
	return sqrt(pow(x - point.x, 2) + pow(y - point.y, 2));
}

Point2D * Point2D::clone() const
{
	return new Point2D(*this);
}


