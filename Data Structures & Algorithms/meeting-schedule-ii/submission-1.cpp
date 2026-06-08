/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start;
        vector<int> end;
        for (auto& it: intervals) {
            start.push_back(it.start);
            end.push_back(it.end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int i = 0, j = 0, cnt = 0, mcnt = 0;
        while (i < start.size() && j < end.size()) {
            if (start[i] < end[j]) {
                cnt++;
                mcnt = max(mcnt, cnt);
                i++;
            }
            else {
                cnt--;
                j++;
            }
        }
        return mcnt;
    }
};
