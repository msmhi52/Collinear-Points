#include <string>
#include <limits>

#include "Point.h"

using namespace std;

Point::Point(int m_x, int m_y): x(m_x), y(m_y){};

double Point::slopeTo(const Point &that){
	if(x == that.x){
		if(y == that.y) return -1*numeric_limits<double>::infinity(); //same points
		else return numeric_limits<double>::infinity(); //vertical
	}
	
	double slope;
	slope = ((double)that.y - (double)y)/((double)that.x - (double)x);
	if(slope == 0) return 0.0; //horizontal
	
	return slope;
}

int Point::compareTo(const Point &that) const{
	if(y == that.y){
		if(x == that.x) return 0;
		else if(x < that.x) return -1;
		else return 1;
	}
	else if(y < that.y) return -1;
	else return 1;
}

// Operator < compares slopes of two points with respect to origin.
bool Point::operator<(Point &p1){
	double slope1 = slopeTo(Point(0,0));
	double slope2 = p1.slopeTo(Point(0,0));
	if(slope1 == slope2){
		if(compareTo(p1) == -1) return true;
		else return false;
	}
	
	return slope1 < slope2;
}

bool Point::operator==(Point &p1){
	if(p1.x == x && p1.y == y) return true;
	return false;
}

bool Point::operator!=(Point &p1){
	if(p1.x == x && p1.y == y) return false;
	return true;
}
