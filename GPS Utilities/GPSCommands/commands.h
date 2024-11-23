#ifndef COMMANDS
#define COMMANDS

#include <vector>
#include <string>
using namespace std;

struct Coordinate
{
    double lat;
    double lon;
};

Coordinate retrieve(vector<Coordinate> coordinates, int pos);

vector<Coordinate> add_waypoint(vector<Coordinate> coordinates, Coordinate new_point, int pos);

vector<Coordinate> remove_waypoint(vector<Coordinate> coordinates, int pos);

#endif