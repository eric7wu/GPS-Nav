#include <iostream>
#include <vector>
#include <stdio.h>
#include "commands.hpp"
// #include "../pathFinding/path.h"
#include "../pathFindingWAltitude/pathAlt.hpp"
using namespace std;
/*
Coordinate retrieve(vector<Coordinate> coordinates, int pos)
{
    if (pos < 1 || pos > coordinates.size())
    {
        cout << "Error; position out of bounds." << endl;
        return coordinates[0]; // return current pos
    }
    else
    {
        return coordinates.at(pos - 1);
    }
}

vector<Coordinate> add_waypoint(vector<Coordinate> coordinates, Coordinate new_coordinate, int pos, vector<directions> &map)
{
    if (pos < 1)
    {
        cout << "Error; position out of bounds." << endl;
        return coordinates;
    }
    else if (pos > coordinates.size()) // coordinate is added to the end of the vector
    {
        coordinates.push_back(new_coordinate);
        Addmapping(coordinates, map, coordinates.size() - 1);
        return coordinates;
    }
    else
    {
        coordinates.insert(coordinates.begin() + (pos - 1), new_coordinate);
        Addmapping(coordinates, map, pos - 1);
        return coordinates;
    }
}

vector<Coordinate> remove_waypoint(vector<Coordinate> coordinates, int pos)
{
    if (pos < 1 || pos > coordinates.size())
    {
        cout << "Error; position out of bounds." << endl;
        return coordinates;
    }
    else
    {
        coordinates.erase(coordinates.begin() + (pos - 1));
        return coordinates;
    }
}
*/
// For coordinatesAlt, or with altitude

CoordinateAlt retrieve(vector<CoordinateAlt> coordinates, int pos)
{
    if (pos < 1 || pos > coordinates.size())
    {
        cout << "Error; position out of bounds." << endl;
        return coordinates[0]; // return current pos
    }
    else
    {
        return coordinates.at(pos - 1);
    }
}

vector<CoordinateAlt> add_waypoint(vector<CoordinateAlt> coordinates, CoordinateAlt new_coordinate, int pos, vector<directionsAlt> &map)
{
    if (pos < 1)
    {
        cout << "Error; position out of bounds." << endl;
        return coordinates;
    }
    else if (pos > coordinates.size()) // coordinate is added to the end of the vector
    {
        coordinates.push_back(new_coordinate);
        Addmapping(coordinates, map, coordinates.size() - 1);
        return coordinates;
    }
    else
    {
        coordinates.insert(coordinates.begin() + (pos - 1), new_coordinate);
        Addmapping(coordinates, map, pos - 1);
        return coordinates;
    }
}

vector<CoordinateAlt> remove_waypoint(vector<CoordinateAlt> coordinates, int pos)
{
    if (pos < 1 || pos > coordinates.size())
    {
        cout << "Error; position out of bounds." << endl;
        return coordinates;
    }
    else
    {
        coordinates.erase(coordinates.begin() + (pos - 1));
        return coordinates;
    }
}
