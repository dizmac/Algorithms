#ifndef ALGORITHMS_GRAPH_H
#define ALGORITHMS_GRAPH_H

#include <bits/stdc++.h>
#include "../Data Structure/Disjoint_Set.h"

namespace Graph {
    struct Edge {
        int _u, _v, _w;

        Edge(int u, int v, int w) {
            _u = u, _v = v, _w = w;
        }
    };

    class EdgeCompare {
    public:
        int operator() (const Edge e1, const Edge e2) const {
            return e1._w > e2._w;
        }
    };

    class Graph {
    public:
        int N, *dist, *visited; std::vector<Edge> mst, adjL, *adj;

        explicit Graph(int K) {
            K++;
            N = K, adj = new std::vector<Edge>[K], dist = new int[K], visited = new int[K];
        }

        [[nodiscard]] int MST() {
            int w = 0;
            DSU::disjoint_set d(N);

            std::sort(adjL.begin(), adjL.end(), EdgeCompare());

            std::vector<Edge>::iterator i;

            for (i = adjL.begin(); i != adjL.end(); i++) {
                int u = i->_u, v = i->_v;

                int set_u = d.find_set(u), set_v = d.find_set(v);

                if (set_u != set_v) {
                    mst.push_back(*i), w += i->_w, d.union_set(set_u, set_v);
                }
            }

            return w;
        }

        [[nodiscard]] int dijkstra(int start, int end) const {
            std::fill(dist, dist + N, INT_MAX);
            std::priority_queue<Edge, std::vector<Edge>, EdgeCompare> q;

            dist[start] = 0, q.emplace(0 ,start, 0);

            while (!q.empty()) {
                auto [t, u, d] = q.top(); q.pop();

                if (visited[u]) continue;
                visited[u] = true;

                for (Edge e : adj[u]) {
                    auto [t, v, w] = e;

                    if (dist[v] > dist[u] + w) dist[v] = dist[u] + w, q.emplace(0, v, dist[v]);
                }
            }

            return (visited[end] ? dist[end] : -1);
        }
    };

}


#endif //ALGORITHMS_GRAPH_H
