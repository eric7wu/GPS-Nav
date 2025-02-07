/*
Contains functions that calculate distance, bearing, heading, and maximum error using latitude and longitude.

This is a helper file.
*/

#ifndef GPS_BASIC
#define GPS_BASIC

#define PI 3.1415926535
#define R 6371000

#include <cmath>

// This macro checks if the angle is counter-clockwise (negative) or clockwise (positive),
// adds 360 degrees if negative and subtracts if positive, and returns the smaller magnitude.
// Ex) Given 270 degrees, it will return -90 as |-90| < |270|
#define MIN(X)                                                             \
    if (bearing < 0)                                                       \
    {                                                                      \
        min = fabs(bearing) < bearing + 360.0 ? bearing : bearing + 360.0; \
    }                                                                      \
    else                                                                   \
    {                                                                      \
        min = bearing < fabs(bearing - 360.0) ? bearing : bearing - 360.0; \
    }

// Converts degrees to radians
double RADIANS(double num);

// Caculates distance between two coordinates
double distance(double lat1, double lon1, double lat2, double lon2);

// Calculates angle between two coordinates
double bearing(double lat1, double lon1, double lat2, double lon2);

// Calculates angle needed to arrive at bearing based on initial direction
// heading is initial direction, bearing is the direction to go to
double findHeading(double heading, double bearing);

// Calculates the maximum error in bearing using a default radius of error of 1m
// Uses distance between two points
double angle_change(double dis);

// Calculates the distance given a latitude, longitude, and altitude
double distanceWAltitude(double lat1, double lon1, double lat2, double lon2, double alt1, double alt2);

double elavationAngle(double lat1, double lon1, double lat2, double lon2, double alt1, double alt2);

#endif