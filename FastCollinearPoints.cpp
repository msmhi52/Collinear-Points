#include "FastCollinearPoints.h"

#include <limits> // numeric_limits
#include <algorithm>
#include <cmath>  // isnan

using namespace std;

FastCollinearPoints::FastCollinearPoints(vector<Point> &points){
	if(points.empty()) throw invalid_argument("Input vector should not be empty");

	if(points.size() >= 4){ // if number of points are smaller than 4, counting collinear points is not nessessary.
		
		sort(points.begin(), points.end()); //sort vector to verify equal points easily.

		vector<Point> new_vec;
		for(size_t i = 0; i < points.size(); i++){ // eliminate all same points.
			if(i != 0 && points[i] == points[i-1]) continue; 
			new_vec.push_back(points[i]);
		}

		points = new_vec;
		new_vec.~vector<Point>();

		for(size_t i = 0; i < points.size(); i++){
			vector<Point> sort_vec; // construct vector to sort in orders of slope.

			for(size_t j = 0; j < points.size(); j++){
				if(j == i) continue;
				sort_vec.push_back(Point(points[j].x - points[i].x, points[j].y - points[i].y));
			}

			sort(sort_vec.begin(), sort_vec.end());

			Point origin = Point(0,0);
			size_t count = 1;
			double now_slope;

			now_slope = sort_vec[0].slopeTo(origin);

			for(size_t idx = 1; idx < sort_vec.size(); idx++){
				if(sort_vec[idx].slopeTo(origin) == now_slope){
					count++;

					if(count >= 3){ // if segment,
						while(sort_vec[++idx].slopeTo(origin) == now_slope){ // check there are other adjacent collinear points.
							count++;
						}

						/* Check out points are in ascending order.
						 * i.e. origin is most smallest and increases subsequently in order of index.
						 * Elements of sort_vec are already in asending order.
						 * Only thing to determine is that the smallest element of sort_vec is larger than origin.
						 */
						if(sort_vec[idx - count].compareTo(origin) != 1) continue;

						/* Segments in ascending order.
						 * Save each point after parallel movement.
						 */
						Point *front = new Point(points[i].x, points[i].y);
						Point *end = new Point(sort_vec[idx-1].x + points[i].x, sort_vec[idx-1].y + points[i].y);
						segments.push_back(LineSegment(front, end));

						now_slope = sort_vec[idx].slopeTo(origin);
					}
				}
				else{
					now_slope = sort_vec[idx].slopeTo(origin);
					count = 1;
				}
			}		
		}
	}
}

int FastCollinearPoints::numberOfSegments(){
	return segments.size();
}
