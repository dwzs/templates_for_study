/* Taken from utexas-art-ros-pkg:art_vehicle/applanix */

/*
 * Conversions between coordinate systems.
 *
 * Includes LatLong<->UTM.
 */

#include "utm.hpp"
#include <iostream>

using namespace std;

int main()
{
    // static inline void LLtoUTM(const double Lat, const double Long,
    //                        double &UTMNorthing, double &UTMEasting,
    //                        char* UTMZone)

    double UTMNorthing = 0;
    double UTMEasting = 0;
    std::string UTMZone;
    gps_common::LLtoUTM(1,1,UTMNorthing,UTMEasting,UTMZone);   //转换经纬度坐标成utm坐标

    cout << "UTMNorthing: " << UTMNorthing << endl;
    cout << "UTMEasting: " << UTMEasting << endl;
    cout << "UTMZone: " << UTMZone << endl;

}