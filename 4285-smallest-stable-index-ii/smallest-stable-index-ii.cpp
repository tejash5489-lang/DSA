class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
         int n = nums.size();
        vector<int> mini(n);
        int minii = INT_MAX;

        for (int i = n - 1; i >= 0; i--) {
            minii = min(minii, nums[i]);
            mini[i] = minii;
        }

        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            if (maxi - mini[i] <= k)
                return i;
        }
        return -1;
    }
};