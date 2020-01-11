#pragma once
class Point2D
{
protected:
	double x;
	double y;
public:
	Point2D();
	Point2D(double x, double y);
	double getDistanceTo(const Point2D& point) const;
	virtual Point2D* clone() const;
};

