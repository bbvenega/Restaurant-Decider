#ifndef USER_H
#define USER_H


#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct User {
    double latitude;
    double longitude;
    vector<int> rankings;
};


pair<double, double> getUserLocation();

#endif