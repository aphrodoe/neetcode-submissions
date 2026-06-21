class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int FindPar(int node) {
        if (node == parent[node]) return node;
        else return parent[node] = FindPar(parent[node]);
    }

    void Union(int u, int v) {
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
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int, pair<int, int>>> edges;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, {i, j}});
            }
        }
        sort(edges.begin(), edges.end());

        DisjointSet ds(n);
        int sum = 0;
        for (auto& it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if (ds.FindPar(u) != ds.FindPar(v)) {
                ds.Union(u, v);
                sum += wt;
            }
        }

        return sum;
    }
};
