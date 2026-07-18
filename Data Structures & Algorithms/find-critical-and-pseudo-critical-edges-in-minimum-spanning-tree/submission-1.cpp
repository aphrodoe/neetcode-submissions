class disjointSet {
private:
    vector<int> parent;
    vector<int> size;

public:
    disjointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findParent(int node) {
        if (parent[node] == node) return parent[node];
        else return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findParent(u), pv = findParent(v);
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
    int mst(int n, vector<vector<int>>& edges, int ignore, disjointSet ds, int sum) {
        for (int i = 0; i < edges.size(); i++) {
            int wt = edges[i][0], u = edges[i][1], v = edges[i][2], ind = edges[i][3];
            if (ind == ignore) continue;
            if (ds.findParent(u) != ds.findParent(v)) {
                sum += wt;
                ds.unionBySize(u, v);
            }
        }
        return sum;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> sortp;
        for (int i = 0; i < edges.size(); i++) {
            vector<int> edge = {edges[i][2], edges[i][0], edges[i][1], i};
            sortp.push_back(edge);
        }
        sort(sortp.begin(), sortp.end());

        disjointSet ds(n);
        int m = mst(n, sortp, -1, ds, 0);

        vector<vector<int>> ans(2);
        for (int i = 0; i < sortp.size(); i++) {
            disjointSet dsi(n);
            int mr = mst(n, sortp, i, dsi, 0);
            if (mr != m) ans[0].push_back(i);
            else {
                int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
                dsi.unionBySize(u, v);
                int minc = mst(n, sortp, i, dsi, wt);
                if (minc == m) ans[1].push_back(i);
            }
        }

        return ans;
    }
};