#include <iostream>
#include <vector>
#include <stdio.h>
#include "commands.h"
using namespace std;

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

vector<Coordinate> add_waypoint(vector<Coordinate> coordinates, Coordinate new_coordinate, int pos)
{
    if (pos < 1)
    {
        cout << "Error; position out of bounds." << endl;
        return coordinates;
    }
    else if (pos > coordinates.size()) // coordinate is added to the end of the vector
    {
        coordinates.push_back(new_coordinate);
        return coordinates;
    }
    else
    {
        coordinates.insert(coordinates.begin() + (pos - 1), new_coordinate);
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