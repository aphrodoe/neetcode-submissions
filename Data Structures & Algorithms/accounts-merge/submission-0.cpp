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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string, int> mp;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (mp.find(accounts[i][j]) != mp.end()) {
                    ds.Union(mp[accounts[i][j]], i);
                }
                else mp[accounts[i][j]] = i;
            }
        }

        vector<set<string>> temp(n);
        for (int i = 0; i < n; i++) {
            int par = ds.FindParent(i);
            for (int j = 1; j < accounts[i].size(); j++) {
                temp[par].insert(accounts[i][j]);
            }
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (temp[i].size() == 0) continue;
            vector<string> account;
            account.push_back(accounts[i][0]);
            vector<string> emails;
            for (const string& email : temp[i]) emails.push_back(email);
            account.insert(account.end(), emails.begin(), emails.end());
            ans.push_back(account);
        }

        return ans;
        
    }
};