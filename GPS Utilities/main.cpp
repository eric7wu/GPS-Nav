#include "GPSCommands/commands.cpp"
#include "pathFinding/path.cpp"
#include <vector>
#include <string>
#include <stdio.h>
#include <cmath>
#include <iostream>
using namespace std;

/*
void add(vector<Coordinate> &coordinates, Coordinate coord, int index, vector<directions> map)
{
    add_waypoint(coordinates, coord, index);
}
*/

int main()
{
    vector<Coordinate> coordinates = {
        {43.470746, -80.553317},
        {43.472182, -80.547994}};
    vector<directions> map = {};
    mapping(coordinates, map);
    add_waypoint(coordinates, {43.400746, -80.603317}, 2, map);
}