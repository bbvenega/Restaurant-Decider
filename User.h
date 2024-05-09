#ifndef USER_H
#define USER_H


#include <iostream>
#include <string>
#include <vector>
#include <utility>


struct User {
    double latitude;
    double longitude;
    vector<int> rankings;
};


pair<double, double> getUserLocation(const string& address, const string& apikey);

#endif