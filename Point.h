#ifndef __PoiNTS_
#define __PoiNTS_

class Point{
public:
	Point(int m_x, int m_y);

	int compareTo(const Point &that) const;
	double slopeTo(const Point &that);

	bool operator<(Point &p1);
	bool operator==(Point &p1);
	bool operator!=(Point &p1);

	int x;
	int y;
};


#endif
