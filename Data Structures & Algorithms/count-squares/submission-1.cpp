struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        return hash<int>()(v[0]) ^ (hash<int>()(v[1]) << 1);
    }
};

class CountSquares {
public:
    unordered_map<vector<int>, int, VectorHash> mp;

    CountSquares() {

    }
    
    void add(vector<int> point) {
        mp[point]++;
    }
    
    int count(vector<int> point) {
        
        int cnt = 0;
        int tempc = 1;
        vector<pair<vector<int>, int>> tempp;

        // top right
        for (auto& it: mp) {
            if (it.first[1] == point[1] && it.first[0] < point[0]) tempp.push_back({it.first, it.second});
        }

        for (int i = 0; i < tempp.size(); i++) {
            int d = point[0] - tempp[i].first[0];
            tempc *= tempp[i].second;
            if (mp.find({point[0], point[1] - d}) != mp.end()) {
                tempc *= mp[{point[0], point[1] - d}];
            }
            else tempc = 0;
            if (mp.find({tempp[i].first[0], tempp[i].first[1] - d}) != mp.end()) {
                tempc *= mp[{tempp[i].first[0], tempp[i].first[1] - d}];
            }
            else tempc = 0;
            cnt += tempc;
            tempc = 1;
        }

        tempp.clear();

        // bottom right
        for (auto& it: mp) {
            if (it.first[1] == point[1] && it.first[0] > point[0]) tempp.push_back({it.first, it.second});
        }

        for (int i = 0; i < tempp.size(); i++) {
            int d = tempp[i].first[0] - point[0];
            tempc *= tempp[i].second;
            if (mp.find({point[0], point[1] - d}) != mp.end()) {
                tempc *= mp[{point[0], point[1] - d}];
            }
            else tempc = 0;
            if (mp.find({tempp[i].first[0], tempp[i].first[1] - d}) != mp.end()) {
                tempc *= mp[{tempp[i].first[0], tempp[i].first[1] - d}];
            }
            else tempc = 0;
            cnt += tempc;
            tempc = 1;
        }

        tempp.clear();

        // top left
        for (auto& it: mp) {
            if (it.first[1] == point[1] && it.first[0] < point[0]) tempp.push_back({it.first, it.second});
        }

        for (int i = 0; i < tempp.size(); i++) {
            int d = point[0] - tempp[i].first[0];
            tempc *= tempp[i].second;
            if (mp.find({point[0], point[1] + d}) != mp.end()) {
                tempc *= mp[{point[0], point[1] + d}];
            }
            else tempc = 0;
            if (mp.find({tempp[i].first[0], tempp[i].first[1] + d}) != mp.end()) {
                tempc *= mp[{tempp[i].first[0], tempp[i].first[1] + d}];
            }
            else tempc = 0;
            cnt += tempc;
            tempc = 1;
        }

        tempp.clear();

        // bottom left
        for (auto& it: mp) {
            if (it.first[1] == point[1] && it.first[0] > point[0]) tempp.push_back({it.first, it.second});
        }

        for (int i = 0; i < tempp.size(); i++) {
            int d = tempp[i].first[0] - point[0];
            tempc *= tempp[i].second;
            if (mp.find({point[0], point[1] + d}) != mp.end()) {
                tempc *= mp[{point[0], point[1] + d}];
            }
            else tempc = 0;
            if (mp.find({tempp[i].first[0], tempp[i].first[1] + d}) != mp.end()) {
                tempc *= mp[{tempp[i].first[0], tempp[i].first[1] + d}];
            }
            else tempc = 0;
            cnt += tempc;
            tempc = 1;
        }

        return cnt;
    }
};
