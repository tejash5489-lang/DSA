class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0, mini = 0;

        for (int i = 1; i < n; i++) {
            if (nums[maxi] > nums[i]) {
                maxi = i;
            }
            if (nums[mini] < nums[i]) {
                mini = i;
            }
        }

        int l = min(mini, maxi);
        int r = max(maxi, mini);

        return min({l + 1 + n - r, r + 1, n - l});
    }
    };