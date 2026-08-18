class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
 int n = nums.size();

        // Case 1: k == 1
        // Every subarray has only one element.
        // So we need the largest element that occurs exactly once.
        if (k == 1) {
            unordered_map<int, int> mp;

            for (int x : nums) {
                mp[x]++;
            }

            int ans = -1;

            for (auto& [x, freq] : mp) {
                if (freq == 1) {
                    ans = max(ans, x);
                }
            }

            return ans;
        }

        // Case 2: k == n
        // There is only ONE subarray: the entire array.
        // Therefore every element belongs to exactly one subarray.
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // Case 3: 1 < k < n
        // Only nums[0] and nums[n-1] can be almost missing.
        unordered_map<int, int> mp;

        for (int x : nums) {
            mp[x]++;
        }

        int ans = -1;

        if (mp[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }

        if (mp[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};