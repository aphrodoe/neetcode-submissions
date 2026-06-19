class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        for (string& w : wordList) words.insert(w);
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        if (beginWord == endWord) return 0;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            string s = it.first;
            for (int i = 0; i < s.size(); i++) {
                string temp = s;
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    if (words.find(temp) != words.end()) {
                        if (temp == endWord) return it.second + 1;
                        else {
                            words.erase(temp);
                            q.push({temp, it.second + 1});
                        }
                    }
                }
            }
        }

        return 0;
    }
};
