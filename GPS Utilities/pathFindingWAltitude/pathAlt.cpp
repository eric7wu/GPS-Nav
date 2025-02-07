#include <stdio.h>
#include <cmath>
#include "../GPSBasics/gps_basic.hpp"
#include "../GPSCommands/commands.hpp"
#include <iostream>
#include <vector>
using namespace std;

#define PI 3.1415926535
#define R 6371000

void mapping(vector<CoordinateAlt> &coordinates, vector<directionsAlt> &map)
{
    map = {};
    double head = 0.0;

    for (int i = 1; i < coordinates.size(); ++i)
    {
        double dis = distanceWAltitude(coordinates.at(i - 1).lat, coordinates.at(i - 1).lon, coordinates.at(i).lat, coordinates.at(i).lon, coordinates.at(i - 1).alt, coordinates.at(i).alt);
        double bear = bearing(coordinates.at(i - 1).lat, coordinates.at(i - 1).lon, coordinates.at(i).lat, coordinates.at(i).lon);
        double elv = elavationAngle(coordinates.at(i - 1).lat, coordinates.at(i - 1).lon, coordinates.at(i).lat, coordinates.at(i).lon, coordinates.at(i - 1).alt, coordinates.at(i).alt);
        double way = findHeading(head, bear);
        map.push_back({coordinates.at(i - 1), coordinates.at(i), dis, way, elv});

        head = bear;
    }
}

void Addmapping(vector<CoordinateAlt> &coordinates, vector<directionsAlt> &map, int newIndex)
{ // Assumes zero-indexing

    if (newIndex == 0)
    {

        double dis = distanceWAltitude(coordinates.at(0).lat, coordinates.at(0).lon, coordinates.at(1).lat, coordinates.at(1).lon, coordinates.at(0).alt, coordinates.at(1).alt);
        double bear = bearing(coordinates.at(0).lat, coordinates.at(0).lon, coordinates.at(1).lat, coordinates.at(1).lon);
        double elv = elavationAngle(coordinates.at(0).lat, coordinates.at(0).lon, coordinates.at(1).lat, coordinates.at(1).lon, coordinates.at(0).alt, coordinates.at(1).alt);
        double way = findHeading(0, bear);

        map.insert(map.begin(), {coordinates.at(0), coordinates.at(1), dis, way, elv});
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

        double dis = distanceWAltitude(coordinates.at(newIndex - 1).lat, coordinates.at(newIndex - 1).lon, coordinates.at(newIndex).lat, coordinates.at(newIndex).lon, coordinates.at(newIndex - 1).alt, coordinates.at(newIndex).alt);
        double bear = bearing(coordinates.at(newIndex - 1).lat, coordinates.at(newIndex - 1).lon, coordinates.at(newIndex).lat, coordinates.at(newIndex).lon);
        double elv = elavationAngle(coordinates.at(newIndex - 1).lat, coordinates.at(newIndex - 1).lon, coordinates.at(newIndex).lat, coordinates.at(newIndex).lon, coordinates.at(newIndex - 1).alt, coordinates.at(newIndex).alt);
        double way = findHeading(head, bear);
        map.at(newIndex - 1) = {coordinates.at(newIndex - 1), coordinates.at(newIndex), dis, way, elv};
        head = bear;

        dis = distanceWAltitude(coordinates.at(newIndex).lat, coordinates.at(newIndex).lon, coordinates.at(newIndex + 1).lat, coordinates.at(newIndex + 1).lon, coordinates.at(newIndex).alt, coordinates.at(newIndex + 1).alt);
        bear = bearing(coordinates.at(newIndex).lat, coordinates.at(newIndex).lon, coordinates.at(newIndex + 1).lat, coordinates.at(newIndex + 1).lon);
        elv = elavationAngle(coordinates.at(newIndex).lat, coordinates.at(newIndex).lon, coordinates.at(newIndex + 1).lat, coordinates.at(newIndex + 1).lon, coordinates.at(newIndex).alt, coordinates.at(newIndex + 1).alt);
        way = findHeading(head, bear);
        map.insert(map.begin() + newIndex, {coordinates.at(newIndex), coordinates.at(newIndex + 1), dis, way, elv});
        head = bear;
    }

    else if (newIndex == coordinates.size() - 1)
    {
        double head = map.at(map.size() - 1).angle;
        double dis = distanceWAltitude(coordinates.at(newIndex - 1).lat, coordinates.at(newIndex - 1).lon, coordinates.at(newIndex).lat, coordinates.at(newIndex).lon, coordinates.at(newIndex - 1).alt, coordinates.at(newIndex).alt);
        double bear = bearing(coordinates.at(newIndex - 1).lat, coordinates.at(newIndex - 1).lon, coordinates.at(newIndex).lat, coordinates.at(newIndex).lon);
        double elv = elavationAngle(coordinates.at(newIndex - 1).lat, coordinates.at(newIndex - 1).lon, coordinates.at(newIndex).lat, coordinates.at(newIndex).lon, coordinates.at(newIndex - 1).alt, coordinates.at(newIndex).alt);
        double way = findHeading(head, bear);
        map.push_back({coordinates.at(newIndex - 1), coordinates.at(newIndex), dis, way, elv});
    }
    else
    {
        cout << "Improper Index entered, try again." << endl;
    }
}

void seeCoords(vector<CoordinateAlt> coordinates)
{
    for (CoordinateAlt p : coordinates)
    {
        printf("Lat: %f, Lon: %f, Elv: %f\n", p.lat, p.lon, p.alt);
    }
    printf("\n");
}

void seeDirecs(vector<directionsAlt> map)
{
    for (directionsAlt p : map)
    {
        printf("From (%f, %f, %f), To (%f, %f, %f):   Distance: %f, Angle: %f, Elavation: %f\n", p.from.lat, p.from.lon, p.from.alt, p.to.lat, p.to.lon, p.to.alt, p.magnitude, p.angle, p.elavation);
    }
    printf("\n");
}
