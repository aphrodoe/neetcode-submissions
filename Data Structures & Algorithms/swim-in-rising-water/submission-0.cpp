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
    bool check(vector<vector<int>>& grid, int t, int n) {
        DisjointSet ds(n * n);
        vector<int> drow = {-1, 1, 0, 0};
        vector<int> dcol = {0, 0, -1, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > t) continue;
                for (int k = 0; k < 4; k++) {
                    int nr = i + drow[k];
                    int nc = j + dcol[k];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] <= t) {
                        ds.Union(i * n + j, nr * n + nc);
                    }
                }
            }
        }

        return (ds.FindPar(0) == ds.FindPar(n * n - 1));
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        int l = grid[n - 1][n - 1];
        int h = 0;
        for (int i = 0; i < n; i++) h = max(h, *max_element(grid[i].begin(), grid[i].end()));

        int t = h;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (check(grid, mid, n)) {
                t = mid;
                h = mid - 1;
            }
            else l = mid + 1;
        }

        return t;
    }
};