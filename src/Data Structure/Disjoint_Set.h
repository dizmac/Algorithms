#ifndef ALGORITHMS_DISJOINT_SET_H
#define ALGORITHMS_DISJOINT_SET_H

#include <bits/stdc++.h>

namespace DSU {
    class disjoint_set {
    private:
        int *parent, *rank;
    public:
        explicit disjoint_set(int N) {
            parent = new int[N], rank = new int[N];

            for (int i = 1; i <= N; i++) {
                rank[i] = 0, parent[i] = i;
            }
        }

        void make_set(int v) {
            parent[v] = v, rank[v] = 0;
        }

        int find_set(int v) {
            if (v == parent[v])
                return v;

            return parent[v] = find_set(v);
        }

        void union_set(int u, int v) {
            u = find_set(u), v = find_set(v);

            if (u != v) {
                if (rank[u] < rank[v])
                    std::swap(u, v);
                parent[v] = u;
                if (rank[u] == rank[v])
                    rank[u]++;
            }
        }
    };
}

#endif //ALGORITHMS_DISJOINT_SET_H
