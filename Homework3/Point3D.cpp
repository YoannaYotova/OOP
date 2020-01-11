#include "Point3D.h"
#include<math.h>


Point3D::Point3D(): Point2D(),z(0)
{
}

Point3D::Point3D(double x, double y, double z):Point2D(x,y),z(z)
{
}

double Point3D::getDistanceTo(const Point3D & point) const
{
	return sqrt(pow((x-point.x),2)+pow((y-point.y),2)+pow((z-point.z),2));
}

Point3D * Point3D::clone() const
{
	return new Point3D(*this);
}



