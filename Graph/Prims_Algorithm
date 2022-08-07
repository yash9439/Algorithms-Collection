// Graph

#include <bits/stdc++.h>
using namespace std;

void prims(vector<pair<int,int>> * holes, int n, long long int &ans) {
    ans = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
    vector<int> isVisited(n,0);
    que.push({0,n-2});

    while(!que.empty()) {
        pair<int,int> G = que.top();
        que.pop();
        if(isVisited[G.second]) {
            continue;
        }
        isVisited[G.second] = 1;

        ans += G.first;
        int size = holes[G.second].size();

        for(int i = 0 ; i < size ; i++) {
            if(!isVisited[holes[G.second][i].second]) {
                que.push(holes[G.second][i]);
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0) -> sync_with_stdio(0);
    cin.tie(NULL);

        int n;
        cin >> n;

        vector<pair<int,int>> holes[n];
        long long int ans = 0;
        // int isVisited[n];
        vector<pair<int,int>> G;

        for(int i = 0 ; i < n ; i++) {
            int x,y;
            cin >> x >> y;
            G.push_back({x,y});
        }   

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(i == j) {
                    continue;
                }
                holes[i].push_back({min(abs(G[i].first-G[j].first),abs(G[i].second-G[j].second)),j});
            }
        }

        prims(holes,n,ans);
        cout << ans << " ";


    return 0;
}
