class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int alice = 0, bob = 0;
        int i = 0, j = piles.size() - 1;
        bool turn = true;
        while (i < j) {
            if (piles[i] - max(piles[i + 1], piles[j]) > piles[j] - max(piles[i], piles[j - 1])) {
                if (turn) alice += piles[i++];
                else bob += piles[i++];
            }
            else {
                if (turn) alice += piles[j--];
                else bob += piles[j--];
            }
        }
        return (alice > bob);
    }
};