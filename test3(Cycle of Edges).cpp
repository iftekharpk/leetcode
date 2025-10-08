#include <bits/stdc++.h>
using namespace std;

vector<int> parent, rnk;

int findparent_node(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findparent_node(parent[x]);
}

bool unionsets(int a, int b) {
    a = findparent_node(a);
    b = findparent_node(b);
    if (a == b)
     return false; 
    if (rnk[a] < rnk[b]) 
    swap(a, b);
    parent[b] = a;
    if (rnk[a] == rnk[b]) 
    rnk[a]++;
    return true;
}

int main() {
    int N, E;
    cin >> N >> E;

    parent.resize(N + 1);
    rnk.resize(N + 1, 0);

    for (int i = 1; i <= N; i++)
     parent[i] = i;

    int cycle_edges = 0;

    for (int i = 0; i < E; i++) {
        int A, B;
        cin >> A >> B;
        if (!unionsets(A, B)) {
            cycle_edges++; 
        }
    }

    cout << cycle_edges << endl;

    return 0;
}
