class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pi=0;
        int ni=1;
        vector<int> ans(nums.size());

        for(int& num:nums){
            if(num>0){
                ans[pi]=num;
                pi+=2;
            }
            else{
                ans[ni]=num;
                ni+=2;
            }
        }
        return ans;
    }
};