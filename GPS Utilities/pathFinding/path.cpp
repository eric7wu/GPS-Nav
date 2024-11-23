#include <stdio.h>
#include <math.h>
#include "../GPSBasics/gps_basic.cpp"
#include "../GPSCommands/commands.cpp"
#include <iostream>
#include <vector>
using namespace std;

#define PI 3.1415926535
#define R 6371000

typedef struct
{
        Coordinate *from;
        Coordinate *to;
        double magnitude;
        double angle;
} directions;

void InitMapping(vector<Coordinate> &coordinates, vector<directions> &map)
{
        map = {};
        double head = 0.0;

        for (int i = 1; i < coordinates.size(); ++i)
        {
                double dis = distance(coordinates.at(i - 1).lat, coordinates.at(i - 1).lon, coordinates.at(i).lat, coordinates.at(i).lon);
                double bear = bearing(coordinates.at(i - 1).lat, coordinates.at(i - 1).lon, coordinates.at(i).lat, coordinates.at(i).lon);
                double way = findHeading(head, bear);
                map.push_back({&coordinates.at(i - 1), &coordinates.at(i), dis, way});

                head = bear;
        }
}

/*
void addCoord(vector<Coordinate> &coordinates, Coordinate coord, int index, vector<directions> map)
{
        if (index >= 0 && index <= coordinates.size())
        {
                coordinates.insert(coordinates.begin() + index, coord);
                mapping(coordinates, map);
        }
        else
        {
                printf("Index not in range\n");
        }
}

void removeCoord(vector<Coordinate> &coordinates, int index, vector<directions> map)
{
        if (index >= 0 && index <= coordinates.size())
        {
                coordinates.erase(coordinates.begin() + index);
                mapping(coordinates, map);
        }
        else
        {
                printf("Index not in range\n");
        }
}
*/
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
                printf("Distance: %f, Angle: %f\n", p.magnitude, p.angle); // pointers are not pointing ot naything
        }
        printf("\n");
}

int main()
{
        vector<Coordinate> coords = {{43.470746, -80.553317}, {43.472182, -80.547994}, {43.473633, -80.540632}, {43.473647, -80.540562}};
        vector<directions> map = {};
        // mapInit(coords, map);

        InitMapping(coords, map);
        seeDirecs(map);

        Coordinate adds = {43.00000, -80.00000};
        /*
        addCoord(coords, adds, 4, map);

        seeCoords(coords);

        removeCoord(coords, 4, map);
        seeCoords(coords);*/

        return 0;
}