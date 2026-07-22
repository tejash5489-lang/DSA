class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count = 0;
        sort(begin(intervals), end(intervals));
        vector<int> v = intervals[0];

        for (int i = 1; i < n; i++) {

            int curre = intervals[i][1];
            int currs = intervals[i][0];

            int l = v[1];

            if (currs >= l) {
                v = intervals[i];
            }

            else if (curre >= l) {
                count++;
            } 
            else if (curre < l) {
                v = intervals[i];
                count++;
            }
        }
        return count;
    }
};