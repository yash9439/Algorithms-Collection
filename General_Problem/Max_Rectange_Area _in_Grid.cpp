#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;

    vector<vector<char>> arr(n,vector<char>(m));

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            cin >> arr[i][j];
        }
    }

    vector <int> bar(m,0);
    int ans = 0;

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(arr[i][j] == '*') {
                bar[j] = 0;
            }
            else {
                bar[j]++;
            }
        }

        vector <int> nextSmaller(m,m);
        stack <int> s;
        for(int i = 0 ; i < m ; i++) {
            while(!s.empty() && bar[s.top()] > bar[i]) {
                nextSmaller[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        vector <int> prevSmaller(m,-1);
        stack <int> s2;
        for(int i = m-1 ; i >= 0 ; i--) {
            while(!s2.empty() && bar[s2.top()] > bar[i]) {
                prevSmaller[s2.top()] = i;
                s2.pop();
            }
            s2.push(i);
        }


        for(int i = 0 ; i < m ; i++) {
            ans = max(ans,bar[i]*(nextSmaller[i]-prevSmaller[i]-1));
        }
    }

    cout << ans;

    return 0;
}