#pragma once
#include"Point2D.h"
class Point3D: public Point2D
{
	double z;
public:
	Point3D();
	Point3D(double x, double y, double z);
	double getDistanceTo(const Point3D& point) const;
	virtual Point3D* clone() const;
};

