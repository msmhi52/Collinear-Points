#ifndef _FaST_CoLLiNeaR_PoiNTS__
#define _FaST_CoLLiNeaR_PoiNTS__

#include <vector>

#include "Point.h"
#include "LineSegment.h"

using namespace std;

class FastCollinearPoints{
public:
	FastCollinearPoints(vector<Point> &points);

	int numberOfSegments();

	vector<LineSegment> segments;// member

};


#endif
