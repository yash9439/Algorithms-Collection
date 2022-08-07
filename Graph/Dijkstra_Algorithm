// Graph

#include <bits/stdc++.h>
using namespace std;


void dijkstra(int * mess, int k, int n,long long int * dis, vector<pair<int,int>> * cities) {
    priority_queue <int> que;
    vector<int> isVisited(n+1,0);

    for(int i = 0 ; i < k ; i++) {
        dis[mess[i]] = 0;
        que.push(mess[i]);
    } 

    while(!que.empty()) {
        int temp = que.top();
        que.pop();

        isVisited[temp] = 1;
        int size = cities[temp].size();
        for(int i = 0 ; i < size ; i++) {
            if(dis[cities[temp][i].second] > dis[temp]+cities[temp][i].first) {
                dis[cities[temp][i].second] = dis[temp]+cities[temp][i].first;
                que.push(cities[temp][i].second);
            }
        }
    }
 }


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0) -> sync_with_stdio(0);
    cin.tie(NULL);


    int n,m,k;
    cin >> n >> m >> k;

    vector<pair<int,int>> cities[n+1];
    long long int dis[n+1];
    for(int i = 0 ; i < n+1 ; i++) {
        dis[i] = LONG_LONG_MAX;
    }

    int mess[k];
    for(int i = 0 ; i < k ; i++) {
        cin >> mess[i];
    }

    for(int i = 0 ; i < m ; i++) {
        int x,y,z;
        cin >> x >> y >> z;
        cities[x].push_back({z,y});
        cities[y].push_back({z,x});
    }

    dijkstra(mess,k,n,dis,cities);

    for(int i = 1 ; i < n+1 ; i++) {
        cout << dis[i] << " ";
    }

    return 0;
}
