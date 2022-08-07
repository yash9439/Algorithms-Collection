#include <bits/stdc++.h>
using namespace std;
 
struct Matching : vector<int> {
	vector<vector<int>> adj;
	vector<int> rank, low, pos, vis, seen;
	int k{0};
 
	Matching(int n = 0) : vector<int>(n, -1), rank(n) {}
 
	bool add(vector<int> vec) {
		adj.push_back(move(vec));
		low.push_back(0); pos.push_back(0); vis.push_back(0);
		if (!adj.back().empty()) {
			int i = k;
		nxt:
			seen.clear();
			if (dfs(adj.size()-1, ++k-i)) return 1;
			for (auto& v : (seen)) for (auto& e : (adj[v]))
				if (rank[e] < 1e9 && vis[at(e)] < k)
					goto nxt;
			for (auto& v : (seen)) {
				low[v] = 1e9;
				for (auto& w : (adj[v])) rank[w] = 1e9;
			}
		}
		return 0;
	}
 
	bool dfs(int v, int g) {
		if (vis[v] < k) vis[v] = k, seen.push_back(v);
		while (low[v] < g) {
			int e = adj[v][pos[v]];
			if (at(e) != v && low[v] == rank[e]) {
				rank[e]++;
				if (at(e) == -1 || dfs(at(e), rank[e]))
					return at(e) = v, 1;
			} else if (++pos[v] == adj[v].size()) {
				pos[v] = 0; low[v]++;
			}
		}
		return 0;
	}
};


 int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(18);

    // n is the number of vertices in Left
    // m is the number of vertices in Right
    // p is the number of edges

	int n, m, p;
	cin >> n >> m >> p;

	vector<vector<int>> G(n);

    for(int i = 0 ; i < p ; i++) {
		int u, v; cin >> u >> v;
		G[u].push_back(v);
	}

	Matching match(m);
	int ans = 0;
	for (auto& v : (G)) {
		ans += match.add(v);
	}
	cout << ans << '\n';

    for(int i = 0 ; i < m ; i++) {
		if (match[i] != -1) {
			cout << match[i] << ' ' << i << '\n';
		}
	}

	return 0;
}
