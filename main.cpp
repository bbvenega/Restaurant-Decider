#include <iostream>
#include <string>
#include <vector>
#include "Restaurant.h"
#include "User.h"


using namespace std;



int main() {

string address = "1600 Amphitheatre Parkway, Mountain View, CA"; // Google's headquarters
    string apiKey = "AIzaSyC2exgUVYviLDmmZ45U96FXWwUg1B0BQJc"; // Replace with your Google Geocoding API key
    pair<double, double> coordinates = getUserLocation(address, apiKey);

    if (coordinates.first != 0.0 && coordinates.second != 0.0) {
        cout << "Latitude: " << coordinates.first << ", Longitude: " << coordinates.second << endl;
    } else {
        cout << "Failed to retrieve coordinates for the address: " << address << endl;
    }

    return 0;
}
