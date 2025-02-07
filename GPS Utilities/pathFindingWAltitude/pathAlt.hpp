/*
Contains functions to generate a set of directions given a list of gps coordinates.
Can also output these directions and coordinates

This is a helper file
*/

#ifndef PATHAlt_H
#define PATHAlt_H

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define PI 3.1415926535
#define R 6371000

struct CoordinateAlt
{
    double lat;
    double lon;
    double alt;
};

struct directionsAlt
{
    CoordinateAlt from;
    CoordinateAlt to;
    double magnitude;
    double angle;
    double elavation;
};

#include "../GPSBasics/gps_basic.hpp"
#include "../GPSCommands/commands.hpp"

// Generates a list of directions given a list of coordinates
void mapping(vector<CoordinateAlt> &coordinates, vector<directionsAlt> &map);

// Updates the list of directions when a coordinate is added to the list
// A more efficient method
// Uses 0-indexing and newIndex is the location of the new coordinate
void Addmapping(vector<CoordinateAlt> &coordinates, vector<directionsAlt> &map, int newIndex);

// Prints out the coordinates list
void seeCoords(vector<CoordinateAlt> coordinates);

// Prints out the directions list
void seeDirecs(vector<directionsAlt> map);
#endif