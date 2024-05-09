#include <iostream>
#include <vector>
#include <utility>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include "User.h"


using namespace std;
using std:: vector;
using std:: pair;
using json = nlohmann::json;


User :: User() {
    latitude = 0;
    longitude = 0;
    
}

void User :: setCoords(pair<double, double> coords) {
    this->longitude = coords.first;
    this->latitude = coords.second;
}

pair<double,double> User ::  getUserLocation(const string& address, const string& apiKey) {
    


    // The code below constructs the api based on the custom Google GeoLocation API passed in
   string apiURL = "https://maps.googleapis.com/maps/api/geocode/json?address=" + address + "&key=" + apiKey;


    // IF CURL DOESN"T EXIST ~ return with error
    CURL *curl = curl_easy_init();
    if(!curl) {
        cerr << "Failed to initialize cURL session" << endl;
        return make_pair(0.0, 0.0);
    }

    /*
    The code below sets the options for the cURL
    1. sets URL to whhich cURL reqeuest will be sent
    2. sets option to follow redirects
    3. Callback function to handle response data from server.
    */ 

curl_easy_setopt(curl, CURLOPT_URL, apiURL.c_str());
curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

string responseData;

curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, [](char *ptr, size_t size, size_t nmemb, string *data){
    data->append(ptr, size * nmemb);
    return size * nmemb;
});

curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseData);



CURLcode res = curl_easy_perform(curl);


    if(res != CURLE_OK) {
       
        cerr << "Failed to fetch geocoding data from API: " << curl_easy_strerror(res) << endl;
        curl_easy_cleanup(curl);
        return make_pair(0.0,0.0);
    }


    // The code below sets the lat and lng of the given address and returns them as a pair if no error occurs.
    try {
        json jsonRes = json::parse(responseData);

        if(!jsonRes["results"].empty()) {
            double latitude = jsonRes["results"][0]["geometry"]["location"]["lat"];
            double longitude = jsonRes["results"][0]["geometry"]["location"]["lng"];
           return make_pair(latitude, longitude);
        } else {
            cerr << "No results found for the address: " << address << endl;
        }
    } catch (const json:: parse_error &e) {
        cerr << "Failed to parse JSON response: " << e.what() << endl;
    }

    curl_easy_cleanup(curl);

    return make_pair(0.0, 0.0);
   
}