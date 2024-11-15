#include <stdio.h>
#include <math.h>
#include "gps_basic.h"
#define PI 3.1415926535
#define R 6371000

// updated bearing
double bearings(double lat1, double lon1, double lat2, double lon2)
{
        lat1 = RADIANS(lat1);
        lat2 = RADIANS(lat2);
        lon1 = RADIANS(lon1);
        lon2 = RADIANS(lon2);

        double bearing = atan2(sin(lon2 - lon1) * cos(lat2),
                               cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(lon2 - lon1));

        bearing = 180 * (bearing / PI);

        double min = 0;

        if (bearing < 0)
        {
                min = fabs(bearing) < fabs(bearing + 360) ? bearing : bearing + 360;
        }
        else
        {
                min = fabs(bearing) < fabs(bearing - 360) ? bearing : bearing - 360;
        }

        return min;
}

void mapping(int len, double coordinates[][2])
{
        double path[][2] = {};
        double head = 0.0;

        for (int i = 1; i < len; ++i)
        {
                double dis = distance(coordinates[i - 1][0], coordinates[i - 1][1], coordinates[i][0], coordinates[i][1]);
                double bear = bearings(coordinates[i - 1][0], coordinates[i - 1][1], coordinates[i][0], coordinates[i][1]);
                double way = findHeading(head, bear);

                printf("%f %f\n", head, bear);
                printf("Distance (meters) from point %d to point %d: %f, Direction (+ cw, - ccw) to there: %f\n", i, i + 1, dis, way);

                head = bear;
        }
}

int main()
{
        double coors[4][2] = {{43.470746, -80.553317}, {43.472182, -80.547994}, {43.473633, -80.540632}, {43.473647, -80.540562}};
        mapping(4, coors);
        return 0;
}