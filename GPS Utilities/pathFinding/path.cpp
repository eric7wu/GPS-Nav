#include <stdio.h>
#include <cmath>
#include "../GPSBasics/gps_basic.cpp"
#include "../GPSCommands/commands.h"
#include <iostream>
#include <vector>
using namespace std;

#define PI 3.1415926535
#define R 6371000

void mapping(vector<Coordinate> &coordinates, vector<directions> &map)
{
    map = {};
    double head = 0.0;

    for (int i = 1; i < coordinates.size(); ++i)
    {
        double dis = distance(coordinates.at(i - 1).lat, coordinates.at(i - 1).lon, coordinates.at(i).lat, coordinates.at(i).lon);
        double bear = bearing(coordinates.at(i - 1).lat, coordinates.at(i - 1).lon, coordinates.at(i).lat, coordinates.at(i).lon);
        double way = findHeading(head, bear);
        map.push_back({coordinates.at(i - 1), coordinates.at(i), dis, way});

        head = bear;
    }
}

void Addmapping(vector<Coordinate> &coordinates, vector<directions> &map, int newIndex)
{ // Assumes zero-indexing

    if (newIndex == 0)
    {

        double dis = distance(coordinates.at(newIndex).lat, coordinates.at(newIndex).lon, coordinates.at(newIndex + 1).lat, coordinates.at(newIndex + 1).lon);
        double bear = bearing(coordinates.at(newIndex).lat, coordinates.at(newIndex).lon, coordinates.at(newIndex + 1).lat, coordinates.at(newIndex + 1).lon);
        double way = findHeading(0, bear);

        map.insert(map.begin(), {coordinates.at(0), coordinates.at(1), dis, way});
        map.at(1).angle = findHeading(way, map.at(1).angle);
    }
    else if (newIndex > 0 && newIndex < coordinates.size() - 1)

    {
        double head;
        if (newIndex - 2 < 0)
        {
            head = 0;
        }
        else
        {
            head = map.at(newIndex - 2).angle;
        }

        double dis = distance(coordinates.at(newIndex - 1).lat, coordinates.at(newIndex - 1).lon, coordinates.at(newIndex).lat, coordinates.at(newIndex).lon);
        double bear = bearing(coordinates.at(newIndex - 1).lat, coordinates.at(newIndex - 1).lon, coordinates.at(newIndex).lat, coordinates.at(newIndex).lon);
        double way = findHeading(head, bear);
        map.at(newIndex - 1) = {coordinates.at(newIndex - 1), coordinates.at(newIndex), dis, way};
        head = bear;

        dis = distance(coordinates.at(newIndex).lat, coordinates.at(newIndex).lon, coordinates.at(newIndex + 1).lat, coordinates.at(newIndex + 1).lon);
        bear = bearing(coordinates.at(newIndex).lat, coordinates.at(newIndex).lon, coordinates.at(newIndex + 1).lat, coordinates.at(newIndex + 1).lon);
        way = findHeading(head, bear);
        map.insert(map.begin() + newIndex, {coordinates.at(newIndex), coordinates.at(newIndex + 1), dis, way});
        head = bear;
    }

    else if (newIndex == coordinates.size() - 1)
    {
        double head = map.at(map.size() - 1).angle;
        double dis = distance(coordinates.at(newIndex - 1).lat, coordinates.at(newIndex - 1).lon, coordinates.at(newIndex).lat, coordinates.at(newIndex).lon);
        double bear = bearing(coordinates.at(newIndex - 1).lat, coordinates.at(newIndex - 1).lon, coordinates.at(newIndex).lat, coordinates.at(newIndex).lon);
        double way = findHeading(head, bear);
        map.push_back({coordinates.at(newIndex - 1), coordinates.at(newIndex), dis, way});
    }
    else
    {
        cout << "Improper Index entered, try again." << endl;
    }
}

void seeCoords(vector<Coordinate> coordinates)
{
    for (Coordinate p : coordinates)
    {
        printf("Lat: %f, Lon: %f\n", p.lat, p.lon);
    }
    printf("\n");
}

void seeDirecs(vector<directions> map)
{
    for (directions p : map)
    {
        printf("From (%f, %f), To (%f, %f):   Distance: %f, Angle: %f\n", p.from.lat, p.from.lon, p.to.lat, p.to.lon, p.magnitude, p.angle);
    }
    printf("\n");
}
