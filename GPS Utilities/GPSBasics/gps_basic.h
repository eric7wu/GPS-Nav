#ifndef GPS_BASIC
#define GPS_BASIC

#define PI 3.1415926535
#define R 6371000

#include <cmath>

#define MIN(X)                                                             \
    if (bearing < 0)                                                       \
    {                                                                      \
        min = fabs(bearing) < bearing + 360.0 ? bearing : bearing + 360.0; \
    }                                                                      \
    else                                                                   \
    {                                                                      \
        min = bearing < fabs(bearing - 360.0) ? bearing : bearing - 360.0; \
    }

double RADIANS(double num);

double distance(double lat1, double lon1, double lat2, double lon2);

double bearing(double lat1, double lon1, double lat2, double lon2);

double findHeading(double heading, double bearing);

double angle_change(double dis);

#endif