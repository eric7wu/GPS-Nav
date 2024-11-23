#include <iostream>
#include <vector>
#include <stdio.h>
#include "commands.h"
using namespace std;

Coordinate retrieve(vector<Coordinate> coordinates, int pos)
{
    if (pos < 1 || pos > coordinates.size())
    {
        cout << "Error; position out of bounds." << endl;
        return coordinates[0]; // return current pos
    }
    else
    {
        return coordinates.at(pos - 1);
    }
}

vector<Coordinate> add_waypoint(vector<Coordinate> coordinates, Coordinate new_coordinate, int pos)
{
    if (pos < 1 || pos > coordinates.size())
    {
        cout << "Error; position out of bounds." << endl;
        return coordinates;
    }
    else
    {
        coordinates.insert(coordinates.begin() + (pos - 1), new_coordinate);
        return coordinates;
    }
}

vector<Coordinate> remove_waypoint(vector<Coordinate> coordinates, int pos)
{
    if (pos < 1 || pos > coordinates.size())
    {
        cout << "Error; position out of bounds." << endl;
        return coordinates;
    }
    else
    {
        coordinates.erase(coordinates.begin() + (pos - 1));
        return coordinates;
    }
}

void print_coordinates(vector<Coordinate> coordinates)
{
    for (int i = 0; i < coordinates.size(); i++)
    {
        printf("%f, %f", coordinates[i].lat, coordinates[i].lon);
        if (i != coordinates.size() - 1)
        {
            printf(" | ");
        }
    }
    printf("\n");
}

/*
int main()
{
    vector<Coordinate> coordinates = {{43.470746, -80.553317}, {43.472182, -80.547994}};

    Coordinate retrieved = retrieve(coordinates, 2);
    printf("Retrieved coordinate: %f, %f\n", retrieved.lat, retrieved.lon);

    vector<Coordinate> new_coordinates = add_waypoint(coordinates, {43.400746, -80.603317}, 2);
    printf("Updated coordinates: ");
    print_coordinates(new_coordinates);

    new_coordinates = remove_waypoint(new_coordinates, 2);
    printf("Updated coordinates: ");
    print_coordinates(new_coordinates);

    return 0;
}
*/