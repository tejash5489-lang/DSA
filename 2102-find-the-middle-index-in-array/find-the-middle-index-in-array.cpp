class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum = 0, n = nums.size() - 1;
        for (int i = 0; i <= n; i++) {
            sum += nums[i];
        }
        int currsum = 0;
        for (int i = 0; i <= n; i++) {
            if (currsum == sum - currsum - nums[i]) {
                return i;
            }
            currsum += nums[i];
        }
        return -1;
    }
};