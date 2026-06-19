class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;

        for (auto &word : words)
            for (char c : word)
                adj[c];
        
        for (int i = 0; i < words.size() - 1; i++) {
            int s = min(words[i].size(), words[i + 1].size());
            bool flag = false;
            for (int j = 0; j < s; j++) {
                if (words[i][j] != words[i + 1][j]) {
                    adj[words[i][j]].insert(words[i + 1][j]);
                    flag = true;
                    break;
                }
            }
            if (!flag && words[i].size() > words[i + 1].size()) return "";
        }

        unordered_map<char, int> indegree;
        for (auto it : adj) {
            for (char ch : it.second) indegree[ch]++;
        }

        queue<char> q;
        for (auto it: adj) {
            if (indegree.find(it.first) == indegree.end()) {
                q.push(it.first);
                indegree[it.first] = 0;
            }
        }

        string topo;
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            topo.push_back(c);
            if (adj.find(c) != adj.end()) {
                for (auto it : adj[c]) {
                    indegree[it]--;
                    if (indegree[it] == 0) q.push(it);
                }
            }
        }

        return (topo.size() == indegree.size()) ? topo : "";
    }
};
