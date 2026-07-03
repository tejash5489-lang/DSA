class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        long long result = 0;
        long long currwindow = 0;
        unordered_set<int> st;

        while (j < n) {

            while (st.count(nums[j])) {
                currwindow -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            currwindow += nums[j];
            st.insert(nums[j]);

            if (j - i + 1 == k) {
                result = max(result, currwindow);

                currwindow -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
        return result;
    }
};