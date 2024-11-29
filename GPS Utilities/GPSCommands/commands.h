#ifndef COMMANDS
#define COMMANDS

#include <vector>
#include <string>
#include "../pathFinding/path.h"
#include "../GPSBasics/gps_basic.h"
using namespace std;

Coordinate retrieve(vector<Coordinate> coordinates, int pos);

vector<Coordinate> add_waypoint(vector<Coordinate> coordinates, Coordinate new_point, int pos, vector<directions> &map);

vector<Coordinate> remove_waypoint(vector<Coordinate> coordinates, int pos);

#endif