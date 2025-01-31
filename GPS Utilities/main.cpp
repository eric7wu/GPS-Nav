#include "GPSCommands/commands.cpp"
#include "pathFinding/path.cpp"
#include <vector>
#include <string>
#include <stdio.h>
#include <cmath>
#include <iostream>
using namespace std;

/*
UI:

Type in the number of coordinates you want to enter?
10

Please type in your coordinates:
...

Mapping created.

Functions:

add lat lon pos // add point at certain position
rm pos // remove point at certain position
ret pos //retrieve point at given position
sc //see coords
sd //see direcs
q //quit
*/

int main()
{
    vector<Coordinate> coordinates = {};
    vector<directions> map = {};

    int N;
    cout << "Type in the number of coordinates you want to enter?" << endl;
    cin >> N;
    double lat;
    double lon;
    int pos;

    for (int i = 0; i < N; i++)
    {
        cin >> lat;
        cin >> lon;

        coordinates.push_back({lat, lon});
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
            cin >> pos;

            if (coordinates.size() > 1)
            {
                coordinates = add_waypoint(coordinates, {lat, lon}, pos, map);
            }
            else
            {
                coordinates.push_back({lat, lon});
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
            Coordinate point = retrieve(coordinates, pos);
            cout << "Lat: " << point.lat << " Lon: " << point.lon << endl;
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