// Graph
// All Pair Shortest Distance
/*
The problem is to find shortest distances between every pair of vertices 
in a given edge weighted directed or undirected Graph. 
*/

// It handles -ve weight edges
// Not handles -ve loop edges



#include<bits/stdc++.h>
using namespace std;

int min(int a, int b) {
    if(a > b) {
        return b;
    }
    return a;
}


int main() {
    int n,m;
    cin >> n >> m;

    vector<pair<int,int>> cities[n+1];
    int dist[n+1][n+1];
    for(int i = 0 ; i < n+1 ; i++) {
        for(int j = 0 ; j < n+1 ; j++) {
            if(i == j) {
                dist[i][j] = 0;
            } 
            else {
                dist[i][j] = INT_MAX;    
            }
        }
    }

    for(int i = 0 ; i < m ; i++) {
        int x,y,z;
        cin >> x >> y >> z;
        cities[x].push_back({y,z});
        dist[x][y] = z;
    }   

    for(int k = 1 ; k < n+1 ; k++) {
        for(int i = 1; i < n+1 ; i++) {
            for(int j = 1 ; j < n+1 ; j++) {
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }


    for(int i = 1 ; i < n+1 ; i++) {
        for(int j = 1 ; j < n+1 ; j++) {
            if(dist[i][j] == INT_MAX) {
                cout << "I ";
            }
            else {
                cout << dist[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}


