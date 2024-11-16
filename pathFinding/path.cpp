#include <stdio.h>
#include <math.h>
#include "../GPSBasics/gps_basic.h"

#include <iostream>
#include <vector>
using namespace std;

#define PI 3.1415926535
#define R 6371000

typedef struct point
{
        double lat;
        double lon;
} point;

double bearings(double lat1, double lon1, double lat2, double lon2)
{
        lat1 = RADIANS(lat1);
        lat2 = RADIANS(lat2);
        lon1 = RADIANS(lon1);
        lon2 = RADIANS(lon2);

        double bearing = atan2(sin(lon2 - lon1) * cos(lat2),
                               cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(lon2 - lon1));

        bearing = 180 * (bearing / PI);

        double min = 0;

        if (bearing < 0)
        {
                min = fabs(bearing) < bearing + 360 ? bearing : bearing + 360;
        }
        else
        {
                min = bearing < fabs(bearing - 360) ? bearing : bearing - 360;
        }

        return min;
}

void mapping(vector<point> coordinates)
{
        double head = 0.0;

        for (int i = 1; i < coordinates.size(); ++i)
        {
                double dis = distance(coordinates.at(i - 1).lat, coordinates.at(i - 1).lon, coordinates.at(i).lat, coordinates.at(i).lon);
                double bear = bearings(coordinates.at(i - 1).lat, coordinates.at(i - 1).lon, coordinates.at(i).lat, coordinates.at(i).lon);
                double way = findHeading(head, bear);

                printf("Distance (meters) from point %d to point %d: %f, Direction (+ cw, - ccw) to there: %f\n", i, i + 1, dis, way);

                head = bear;
        }
}

void addCoord(vector<point> &coordinates, point coord, int index)
{
        if (index >= 0 && index <= coordinates.size())
        {
                coordinates.insert(coordinates.begin() + index, coord);
                mapping(coordinates);
        }
        else
        {
                printf("Index not in range\n");
        }
}

void removeCoord(vector<point> &coordinates, int index)
{
        if (index >= 0 && index <= coordinates.size())
        {
                coordinates.erase(coordinates.begin() + index);
                mapping(coordinates);
        }
        else
        {
                printf("Index not in range\n");
        }
}

void seeCoords(vector<point> &coordinates)
{
        for (point p : coordinates)
        {
                printf("Lat: %f, Lon: %f\n", p.lat, p.lon);
        }
        printf("\n");
}

int main()
{
        vector<point> coords = {{43.470746, -80.553317}, {43.472182, -80.547994}, {43.473633, -80.540632}, {43.473647, -80.540562}};

        mapping(coords);
        seeCoords(coords);

        point adds = {43.00000, -80.00000};
        addCoord(coords, adds, 4);

        seeCoords(coords);

        removeCoord(coords, 4);
        seeCoords(coords);

        return 0;
}