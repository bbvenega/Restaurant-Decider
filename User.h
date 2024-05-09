#ifndef USER_H
#define USER_H


#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

class User {
    double latitude;
    double longitude;
    vector<int> rankings;

    public:

    User();

     void setCoords(pair<double,double> coordinates);
    pair<double, double> getUserLocation(const string& address, const string& apikey);
};




#endif