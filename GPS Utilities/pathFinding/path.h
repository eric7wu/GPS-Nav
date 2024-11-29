#ifndef PATH_H
#define PATH_H

#include <stdio.h>
#include <math.h>
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

void mapping(vector<Coordinate> &coordinates, vector<directions> &map);

void seeDirecs(vector<directions> map);

void Addmapping(vector<Coordinate> &coordinates, vector<directions> &map, int newIndex);
#endif