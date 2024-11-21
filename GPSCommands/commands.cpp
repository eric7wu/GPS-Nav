#include <iostream>
#include <vector>
#include <string>
#include "commands.h"
using namespace std;

Coordinate retrieve(vector<string> coordinates, int pos)
{
    string co = coordinates.at(pos - 1);
    Coordinate retrieved = {stod(co.substr(0, co.find(","))), stod(co.substr(co.find(",")+1))};
    return retrieved;
}

vector<string> add_waypoint(vector<string> coordinates, string new_point, int pos)
{
    vector<string> updated_coordinates;
    for (int n = 0; n < coordinates.size(); n++)
    {
        if (n + 1 == pos)
        {
            updated_coordinates.push_back(new_point);
        }
        if (n < coordinates.size())
        {
            updated_coordinates.push_back(coordinates.at(n));
        }
    }
    return updated_coordinates;
}

vector<string> remove_waypoint(vector<string> coordinates, int pos)
{
    vector<string> updated_coordinates;
    for (int n = 0; n < coordinates.size(); n++)
    {
        if (n + 1 != pos)
        {
            updated_coordinates.push_back(coordinates.at(n));
        }
    }
    return updated_coordinates;
}

/*
int main()
{
    vector<string> coordinates = {"43.470746, -80.553317", "43.472182, -80.547994"};
    cout << "Retrieved coordinate: " << retrieve(coordinates, 2).lat << ", " << retrieve(coordinates, 2).lon << endl; // cout isn't precise, but the values are accurate
    vector<string> new_coordinates = add_waypoint(coordinates, "43.400746, -80.603317", 1);
    cout << "Updated coordinates: ";
    for (int i = 0; i < new_coordinates.size(); i++)
    {
        cout << new_coordinates[i];
        if (i != new_coordinates.size() - 1)
        {
            cout << " | ";
        }
    }
    cout << endl;
    new_coordinates = remove_waypoint(new_coordinates, 2);
    cout << "Updated coordinates: ";
    for (int i = 0; i < new_coordinates.size(); i++)
    {
        cout << new_coordinates[i];
        if (i != new_coordinates.size() - 1)
        {
            cout << " | ";
        }
    }
    cout << endl;
    return 0;
}
*/