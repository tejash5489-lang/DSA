class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        for(; i < nums.size(); i++){
            int idx = abs(nums[i]);
            if(nums[idx] < 0) break;
            nums[idx] *= -1;
        }
        return abs(nums[i]);
    }
};