#define endline "\n"

#include "Disjoint_Set.h"
#include <bits/stdc++.h>

using namespace std;
using namespace DSU;

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

const int N = 10;

void disjoint_test() {
    disjoint_set dsu(100);
    dsu.make_set(1), dsu.make_set(3);
    dsu.find_set(1);
    dsu.union_set(1, 3);

    cout << dsu.find_set(3) << endline;
}