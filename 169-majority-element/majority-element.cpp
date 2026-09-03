class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int maj = 0;

        for (int i = 0; i < n; i++) {
            if (count == 0) {
                count++;
                maj = nums[i];
            } else if (nums[i] == maj) {
                count++;
            } else {
                count--;
            }
        }
        return maj;
    }
};