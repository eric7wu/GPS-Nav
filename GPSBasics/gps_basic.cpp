#include <stdio.h>
#include <math.h>
#define PI 3.1415926535
#define R 6371000

double lat1 = 43.473633;
double lat2 = 43.473647;
double lon1 = -80.540632;
double lon2 = -80.540562;

double heading = 359;
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

        bearing = 180 * (bearing / PI);

        if (bearing < 0)
                bearing += 360;

        return bearing;
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

int main(void)
{
        double dis = distance(lat1, lon1, lat2, lon2);
        printf("Distance: %f meters\n", dis);
        printf("Bearing: %f (CW is positive, CCW is negative)\n", bearing(lat1, lon1, lat2, lon2));
        printf("Heading: %f (CW is positive, CCW is negative)\n", findHeading(heading, bearing(lat1, lon1, lat2, lon2)));
        printf("Hypothetical maximum angle change: %f", angle_change(dis));
}