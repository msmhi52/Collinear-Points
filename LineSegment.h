#ifndef _LiNeSeGMeNT__
#define _LiNeSeGMeNT__

#include "Point.h"
#include <stdexcept>

class LineSegment{
public:
	LineSegment(Point *m_p, Point *m_q): p(m_p), q(m_q){};

	Point *p;
	Point *q;
};

#endif
