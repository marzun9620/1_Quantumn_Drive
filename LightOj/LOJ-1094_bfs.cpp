#include <stdio.h>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

vector<vector<pair<int, int>>> graph;
bool vis[30005];
long long maxi;
int start;

void bfs(int src) {
    queue<pair<int, long long>> q;
    q.push({src, 0});
    vis[src] = true;

    while (!q.empty()) {
        int u = q.front().first;
        long long dis = q.front().second;
        q.pop();

        if (dis > maxi) {
            maxi = dis;
            start = u;
        }

        for (const auto &edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            if (!vis[v]) {
                vis[v] = true;
                q.push({v, dis + w});
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    for (int cs = 1; cs <= t; cs++) {
        int n;
        cin >> n;

        graph.clear();
        graph.resize(n + 2);

        for (int i = 0; i < n - 1; i++) {
            int x, y, w;
            cin >> x >> y >> w;
            graph[x].emplace_back(y, w);
            graph[y].emplace_back(x, w);
        }

        maxi = numeric_limits<long long>::min();
        memset(vis, 0, sizeof(vis));
        bfs(0);

        maxi = numeric_limits<long long>::min();
        memset(vis, 0, sizeof(vis));
        bfs(start);

        cout << "Case " << cs << ": " << maxi << endl;
    }

    return 0;
}
