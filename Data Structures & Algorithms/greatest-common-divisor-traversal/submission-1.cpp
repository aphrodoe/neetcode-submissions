class DisjointSet {
private:
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int FindParent(int node) {
        if (parent[node] == node) return parent[node];
        else return parent[node] = FindParent(parent[node]);
    }

    void Union(int u, int v) {
        int pu = FindParent(u), pv = FindParent(v);
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
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        DisjointSet ds(n);
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            int n = nums[i];
            for (int j = 2; j <= sqrt(nums[i]); j++) {
                if (n % j == 0) {
                    if (mp.find(j) != mp.end()) ds.Union(mp[j], i);
                    else mp[j] = i;
                    while (n % j == 0) n /= j;
                }
            }
            if (n != 1) {
                if (mp.find(n) != mp.end()) ds.Union(mp[n], i);
                else mp[n] = i;
            }
        }

        int par = ds.FindParent(0);
        for (int i = 1; i < n; i++) {
            if (ds.FindParent(i) != par) return false;
        }
        return true;
    }
};