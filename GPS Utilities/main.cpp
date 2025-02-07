#include "GPSCommands/commands.cpp"
// #include "pathFinding/path.cpp"
#include "pathFindingWAltitude/pathAlt.cpp"
#include <vector>
#include <string>
#include <stdio.h>
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    vector<CoordinateAlt> coordinates = {};
    vector<directionsAlt> map = {};

    int N;
    cout << "Type in the number of coordinates you want to enter?" << endl;
    cin >> N;
    double lat;
    double lon;
    double alt;
    int pos;

    for (int i = 0; i < N; i++)
    {
        cin >> lat;
        cin >> lon;
        cin >> alt;

        coordinates.push_back({lat, lon, alt});
    }

    mapping(coordinates, map);
    cout << endl
         << "Mapping Created." << endl;
    seeCoords(coordinates);
    seeDirecs(map);

    cout << "Anything else?" << endl;
    string token;
    while (true)
    {
        if (cin.fail() || token == "q")
        {
            cout << "exiting..." << endl;
            break;
        }
        cin >> token;

        if (token == "add")
        {
            cin >> lat;
            cin >> lon;
            cin >> alt;
            cin >> pos;

            if (coordinates.size() > 1)
            {
                coordinates = add_waypoint(coordinates, {lat, lon, alt}, pos, map);
            }
            else
            {
                coordinates.push_back({lat, lon, alt});
                mapping(coordinates, map);
            }
        }
        else if (token == "rm")
        {
            cin >> pos;
            coordinates = remove_waypoint(coordinates, pos);
            mapping(coordinates, map);
        }
        else if (token == "ret")
        {
            cin >> pos;
            CoordinateAlt point = retrieve(coordinates, pos);
            cout << "Lat: " << point.lat << " Lon: " << point.lon << " Alt: " << point.alt << endl;
        }
        else if (token == "sc")
        {
            seeCoords(coordinates);
        }
        else if (token == "sd")
        {
            seeDirecs(map);
        }
        else
        {
            cout << "Command is invalid, try again" << endl;
        }
    }
}