class Solution {
public:
    int solve(vector<vector<int>>& job, int i) {

        int l = 0;
        int h = i - 1;
        int ans = -1;

        while (l <= h) {

            int m = l + (h - l) / 2;

            if (job[m][0] <= job[i][1]) {
                ans = m;
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        return ans;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> job(n, vector<int>(3, 0));

        for (int i = 0; i < n; i++) {
            job[i] = {endTime[i], startTime[i], profit[i]};
        }

        sort(job.begin(), job.end());
        vector<int> dp(n, 0);
        dp[0] = job[0][2];

        for (int i = 1; i < n; i++) {
            int exclude = dp[i - 1];
            int include = job[i][2];

            int ind = solve(job, i);
            if (ind != -1)
                include += dp[ind];

            dp[i] = max(include, exclude);
        }
        return dp[n - 1];
    }
};