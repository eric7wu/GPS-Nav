#ifndef COMMANDS
#define COMMANDS

#include <vector>
#include <string>

struct Coordinate
{
    double lat;
    double lon;
};

Coordinate retrieve(const std::vector<std::string>& coordinates, int pos);

std::vector<std::string> add_waypoint(const std::vector<std::string>& coordinates, const std::string& new_point, int pos);

std::vector<std::string> remove_waypoint(const std::vector<std::string>& coordinates, int pos);

#endif