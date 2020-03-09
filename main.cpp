#include "FastCollinearPoints.h"

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv){
	ifstream inFile;
	inFile.open(argv[1]);
	int x, y;
	size_t n;
	inFile >> n;

	vector<Point> points;
	for(size_t i = 0; i < n; i++){
		inFile >> x >> y;
		points.push_back(Point(x,y));
	}

	inFile.close();

	try{
		FastCollinearPoints collinear(points);
		for(size_t i = 0; i < collinear.segments.size(); i++){
			cout << "(" << collinear.segments[i].p->x << ", " << collinear.segments[i].p->y << ")  ->  (" << 
				collinear.segments[i].q->x << ", " << collinear.segments[i].q->y << ")\n";
		}
	} catch(exception &oor){cout << oor.what() << "\n";};

	return 0;
}
