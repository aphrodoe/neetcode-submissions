class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mp;
        int n = hand.size();
        for (int i = 0; i < hand.size(); i++) mp[hand[i]]++;
        if (n % groupSize != 0) return false;
        int groups = n / groupSize;
        for (int i = 0; i < groups; i++) {
            int curr = mp.begin()->first;
            if (mp[curr] == 1) mp.erase(curr);
            else mp[curr]--;
            for (int i = 1; i < groupSize; i++) {
                if (mp.find(curr + 1) == mp.end()) return false;
                else {
                    curr++;
                    if (mp[curr] == 1) mp.erase(curr);
                    else mp[curr]--;
                }
            }
        }
        return true;
    }
};
