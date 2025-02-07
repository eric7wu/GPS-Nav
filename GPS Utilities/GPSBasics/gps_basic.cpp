#include <cmath>
#include "gps_basic.hpp"
#define PI 3.1415926535
#define R 6371000

#define MIN(X)                                                             \
    if (bearing < 0)                                                       \
    {                                                                      \
        min = fabs(bearing) < bearing + 360.0 ? bearing : bearing + 360.0; \
    }                                                                      \
    else                                                                   \
    {                                                                      \
        min = bearing < fabs(bearing - 360.0) ? bearing : bearing - 360.0; \
    }

double error = 1;

double RADIANS(double num)
{
    return num * (PI / 180);
}

double distance(double lat1, double lon1, double lat2, double lon2)
{

    double dis = acos((sin(RADIANS(lat1)) * sin(RADIANS(lat2))) + (cos(RADIANS(lat1)) * cos(RADIANS(lat2))) * (cos(RADIANS(lon2) - RADIANS(lon1)))) * R;
    return dis;
}

double bearing(double lat1, double lon1, double lat2, double lon2)
{
    lat1 = RADIANS(lat1);
    lat2 = RADIANS(lat2);
    lon1 = RADIANS(lon1);
    lon2 = RADIANS(lon2);

    double bearing = atan2(sin(lon2 - lon1) * cos(lat2),
                           cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(lon2 - lon1));

    bearing = 180.0 * (bearing / PI);

    double min = 0;

    MIN(bearing);

    return min;
}

double findHeading(double heading, double bearing)
{
    double header = bearing - heading;

    return fabs(header) > header + 360 ? header + 360 : header;
}

double angle_change(double dis)
{
    double hypo_change = 180 * (asin(2 * error / dis) / PI);

    return hypo_change;
}

double distanceWAltitude(double lat1, double lon1, double lat2, double lon2, double alt1, double alt2)
{
    double flatDis = distance(lat1, lon1, lat2, lon2);

    double elavationChange = fabs(alt1 - alt2);

    return sqrt(flatDis * flatDis + elavationChange * elavationChange);
}

double elavationAngle(double lat1, double lon1, double lat2, double lon2, double alt1, double alt2)
{
    double dis = distance(lat1, lon1, lat2, lon2);
    double elavationChange = alt2 - alt1; // Assumes alt2 is the point you want to go to

    return atan2(elavationChange, dis);
}