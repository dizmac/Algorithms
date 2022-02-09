#define endline "\n"

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<string> vs;

template<class T>
T scan() {
    T v;
    cin >> v;
    return v;
}

struct Edge {
    int _v, _w;

    Edge(int v, int w) {
        _v = v, _w = w;
    }
};


class EdgeCompare {
public:
    int operator() (const Edge e1, const Edge e2) const {
        return e1._w > e2._w;
    }
};

int N, M, visited[1001], dist[1001];
vector<Edge> adj[1001];



int sssp() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    fill(dist, dist+1002, INT_MAX);
    priority_queue<Edge, vector<Edge>, EdgeCompare> q;

    dist[1] = 0, q.emplace(1, 0);

    while (!q.empty()) {
        auto [u, d] = q.top(); q.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (Edge e : adj[u]) {
            auto [v, w] = e;

            if (dist[v] > dist[u] + w) dist[v] = dist[u] + w, q.emplace(v, dist[v]);
        }
    }

    return dist[1000];
}