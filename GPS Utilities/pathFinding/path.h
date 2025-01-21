/*
Contains functions to generate a set of directions given a list of gps coordinates.
Can also output these directions and coordinates

This is a helper file
*/

#ifndef PATH_H
#define PATH_H

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include "../GPSBasics/gps_basic.h"
#include "../GPSCommands/commands.h"
using namespace std;

#define PI 3.1415926535
#define R 6371000

struct Coordinate
{
    double lat;
    double lon;
};

typedef struct
{
    Coordinate from;
    Coordinate to;
    double magnitude;
    double angle;
} directions;

// Generates a list of directions given a list of coordinates
void mapping(vector<Coordinate> &coordinates, vector<directions> &map);

// Updates the list of directions when a coordinate is added to the list
// A more efficient method
// Uses 0-indexing and newIndex is the location of the new coordinate
void Addmapping(vector<Coordinate> &coordinates, vector<directions> &map, int newIndex);

// Prints out the coordinates list
void seeCoords(vector<Coordinate> coordinates);

// Prints out the directions list
void seeDirecs(vector<directions> map);
#endif