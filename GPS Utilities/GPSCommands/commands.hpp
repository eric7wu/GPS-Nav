#ifndef COMMANDS
#define COMMANDS

/*
Contains functions that can add, remove, and see waypoints.

This is a helper file.
*/

#include <vector>
#include <string>
#include "../pathFinding/path.hpp"
#include "../pathFindingWAltitude/pathAlt.hpp"
// #include "../GPSBasics/gps_basic.hpp"
using namespace std;

// Outputs the coordinate at the specified index
// 1-based indexing
// If pos is not between 1 and the number of coordinates, it returns the first coordinate
Coordinate retrieve(vector<Coordinate> coordinates, int pos);

// Adds the coordinate at the specified index and automatically updates the directions
// 1-based indexing
// If pos is larger than the number of coordinates, it adds it to the end
// If pos is smaller than 1, it outputs the error and returns the array unchanged
vector<Coordinate> add_waypoint(vector<Coordinate> coordinates, Coordinate new_point, int pos, vector<directions> &map);

// Removes the coordinate at the specified index but does not automatically update the directions
// 1-based indexing
// If pos is not between 1 and the number of coordinates, it outputs the error and returns the array unchanged
vector<Coordinate> remove_waypoint(vector<Coordinate> coordinates, int pos);

CoordinateAlt retrieve(vector<CoordinateAlt> coordinates, int pos);
vector<CoordinateAlt> add_waypoint(vector<CoordinateAlt> coordinates, CoordinateAlt new_point, int pos, vector<directionsAlt> &map);
vector<CoordinateAlt> remove_waypoint(vector<CoordinateAlt> coordinates, int pos);

#endif