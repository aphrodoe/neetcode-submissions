class DisjointSet {
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }

    int FindPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = FindPar(parent[node]);
    }

    void UnionBySize(int u, int v) {
        int pu = FindPar(u), pv = FindPar(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);

        for (int i = 0; i < n; i++) {
            int u = edges[i][0], v = edges[i][1];
            if (ds.FindPar(u) != ds.FindPar(v)) ds.UnionBySize(u, v);
            else return {u, v};
        } 

    }
};
