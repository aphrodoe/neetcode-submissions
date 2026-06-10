class CountSquares {
public:
    unordered_map<long, int> cnt;
    vector<vector<int>> pts;

    long get(int a, int b) {
        return (static_cast<long>(a) << 32 | static_cast<long>(b));
    }

    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        long key = get(point[0], point[1]);
        cnt[key]++;
        pts.push_back(point);
    }
    
    int count(vector<int> point) {
        int px = point[0], py = point[1];
        int res = 0;

        for (auto& pt: pts) {
            int x = pt[0], y = pt[1];
            if (abs(px - x) != abs(py - y) || x == px || y == py) continue;
            res += cnt[get(x, py)] * cnt[get(px, y)];
        }
        return res;
    }
};
