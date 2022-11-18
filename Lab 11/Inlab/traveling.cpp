#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "middleearth.h"

/**
 * @author Alisha Meena Gursahaney amg9zd
 * @file middleearth.h
 */ 


float computeDistance(MiddleEarth& me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

/**
 * @brief The Traveling Salesperson main
 * 
 * Find the least costly path that travels to each of the cities, in any order/
 * A brute-force method that tries every possible path combination.
 * 
 * @param argc int commandline passing parameter
 * @param argv char commandline parameters
 * @return 0
 * @pre cities are unsorted and paths are not computed
 * @post least costly path is computed and printed
 */ 

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    // TODO: YOUR CODE HERE

    // first city in the list
    // permutation i (n-1)! to exclude first city
    // because we are starting in the first city
    // store, then take out of sorting permutation
    string firstcity = dests[0];

    // sorting permutation, excluding 1st city
    sort(dests.begin()+1, dests.end());

    // computing the minimum path from beginning to end using our function
    float minimum_path = computeDistance(me, firstcity, dests);
    
    // copy of dests list to alter and then return
    vector<string> updated_dests = dests;

    // iterate through distances to find the minimum
    while(next_permutation(dests.begin()+1, dests.end())) {
        float next_path = computeDistance(me, firstcity, dests);
        if ( next_path < minimum_path) {
            minimum_path = next_path;
            updated_dests = dests;
        }
    }

    cout << "Minimum path has distance " << minimum_path << ": ";

    printRoute(firstcity, updated_dests);

    // cout << firstcity;

    
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.

/**
 * @brief calculate distance of path
 * 
 * @return float total distance of path
 * @param me list of cities
 * @param start first city
 * @param dests list of cities
 */ 

float computeDistance(MiddleEarth& me, const string& start, vector<string> dests) {
    // TODO: YOUR CODE HERE
    // avoids overloading error
    string temp = dests[0];
    // distance from first to last element
    // starting sum, then add edge distances as iterating through
    float sum = me.getDistance(temp, dests[dests.size()-1]);
    
    // vector<string>::iterator i = dests.begin();
    for(int i = 0; i < dests.size(); i++) {
        float dist = me.getDistance(temp, dests[i]);
        sum += dist;
        // change start to previous end city to keep adding edge distances one at a time
        // overloaded
        // create temp value
        temp = dests[i];
        // i++;
    }

    return sum;
}

/**
 * @brief print path distance
 * 
 * @param start first city
 * @param dests list of cities
 */ 

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE
    // vector<string>::iterator i = dests.begin();
    for(int i = 0; i < dests.size(); i++) {
        cout << dests[i] << " -> ";
        // i++; 
    }
    // cout << firstcity << endl;
    cout << start << endl;
}
