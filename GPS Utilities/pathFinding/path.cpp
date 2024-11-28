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
        Coordinate from;
        Coordinate to;
        double magnitude;
        double angle;
} directions;

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

void Addmapping(vector<Coordinate> &coordinates, vector<directions> &map, int start, int end)
{
        double head = map.at(start - 2).angle;
        if (start > 0 && end + 1 < coordinates.size())
        {

                double dis = distance(coordinates.at(start - 1).lat, coordinates.at(start - 1).lon, coordinates.at(start).lat, coordinates.at(start).lon);
                double bear = bearing(coordinates.at(start - 1).lat, coordinates.at(start - 1).lon, coordinates.at(start).lat, coordinates.at(start).lon);
                double way = findHeading(head, bear);
                map.at(start - 1) = {coordinates.at(start - 1), coordinates.at(start), dis, way};

                head = bear;
        }
        else if (start > 0)
        {
                double dis = distance(coordinates.at(start - 1).lat, coordinates.at(start - 1).lon, coordinates.at(start).lat, coordinates.at(start).lon);
                double bear = bearing(coordinates.at(start - 1).lat, coordinates.at(start - 1).lon, coordinates.at(start).lat, coordinates.at(start).lon);
                double way = findHeading(head, bear);
                map.push_back({coordinates.at(start - 1), coordinates.at(start), dis, way});

                head = bear;
        }
        // coords: {1, 2}, {2, 3}, {3, 4}, {4, 4}, {4,5 } //{3,4} & {4, 4} added, s = 2, e = 3

        for (int i = start + 1; i < end + 1; ++i)
        {
                double dis = distance(coordinates.at(i - 1).lat, coordinates.at(i - 1).lon, coordinates.at(i).lat, coordinates.at(i).lon);
                double bear = bearing(coordinates.at(i - 1).lat, coordinates.at(i - 1).lon, coordinates.at(i).lat, coordinates.at(i).lon);
                double way = findHeading(head, bear);
                map.insert(map.begin() + i - 1, {coordinates.at(i - 1), coordinates.at(i), dis, way});

                head = bear;
        }

        if (end + 1 < coordinates.size())
        {
                double dis = distance(coordinates.at(end).lat, coordinates.at(end).lon, coordinates.at(end + 1).lat, coordinates.at(end + 1).lon);
                double bear = bearing(coordinates.at(end).lat, coordinates.at(end).lon, coordinates.at(end + 1).lat, coordinates.at(end + 1).lon);
                double way = findHeading(head, bear);
                map.insert(map.begin() + end, {coordinates.at(end), coordinates.at(end + 1), dis, way});

                head = bear;
        }
        else
        {
                double dis = distance(coordinates.at(end).lat, coordinates.at(end).lon, coordinates.at(end + 1).lat, coordinates.at(end + 1).lon);
                double bear = bearing(coordinates.at(end).lat, coordinates.at(end).lon, coordinates.at(end + 1).lat, coordinates.at(end + 1).lon);
                double way = findHeading(head, bear);
                map.push_back({coordinates.at(end), coordinates.at(end + 1), dis, way});

                head = bear;
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

void addCoord(vector<Coordinate> &coordinates, Coordinate coord, int index, vector<directions> map)
{
        if (index >= 0 && index <= coordinates.size())
        {
                coordinates.insert(coordinates.begin() + index, coord);
                // mapping(coordinates, map);
        }
        else
        {
                printf("Index not in range\n");
        }
}
/*
int main()
{
        vector<Coordinate> coords = {{43.470746, -80.553317}, {43.472182, -80.547994}, {43.473633, -80.540632}, {43.473647, -80.540562}};
        vector<directions> map = {};

        mapping(coords, map);
        seeDirecs(map);

        Coordinate adds = {43.00000, -80.00000};
        addCoord(coords, adds, 4, map);
        addCoord(coords, {43.5, -80.5}, 4, map);

        Addmapping(coords, map, 4, 5);
        seeDirecs(map);

        return 0;
}*/