//This program that I made in C++ uses heaps to find the minimum cost to connect all cities:

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = INT_MAX;

// Function to find the minimum cost to connect all cities
int minimumCostToConnectCities(vector<vector<int>>& city) {
    int n = city.size();

    // Priority queue to store edges (cost, destination)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    // Array to store whether a city is visited or not
    vector<bool> visited(n, false);

    // Start from the first city (you can start from any city)
    int startCity = 0;
    visited[startCity] = true;

    // Add all edges from the start city to the priority queue
    for (int i = 0; i < n; ++i) {
        if (city[startCity][i] > 0) {
            minHeap.push({city[startCity][i], i});
        }
    }

    int totalCost = 0;

    // Loop until all cities are visited
    while (!minHeap.empty()) {
        // Get the minimum cost edge
        pair<int, int> edge = minHeap.top();
        minHeap.pop();

        int cost = edge.first;
        int currentCity = edge.second;

        // If the destination city is not visited
        if (!visited[currentCity]) {
            visited[currentCity] = true;
            totalCost += cost;

            // Add all edges from the current city to the priority queue
            for (int i = 0; i < n; ++i) {
                if (!visited[i] && city[currentCity][i] > 0) {
                    minHeap.push({city[currentCity][i], i});
                }
            }
        }
    }

    return totalCost;
}

int main() {
    // Input: matrix(city) form
    vector<vector<int>> city = {
        {0, 1, 2, 0},
        {1, 0, 3, 4},
        {2, 3, 0, 5},
        {0, 4, 5, 0}
    };

    int minCost = minimumCostToConnectCities(city);

    // Output: Minimum cost to connect all cities
    cout << "Minimum cost to connect all cities: " << minCost << endl;

    return 0;
}
