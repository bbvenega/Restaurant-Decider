#ifndef RESTAURANT_H
#define RESTAURANT_H


#include <iostream>
#include <string>
#include <vector>
#include "User.h"

using namespace std;

struct Restaurant {
    string name;
    double latitude;
    double longtitude;
    vector<int> ratings;
};

vector<Restaurant> getRestaurants(double userLat, double userLong);

int calculateTotalScore(const Restaurant& restaurant, const User& user1, const User& user2);

int calculateAlignmentScore(const Restaurant& restaurant, const User& user1, const User& user2);

#endif