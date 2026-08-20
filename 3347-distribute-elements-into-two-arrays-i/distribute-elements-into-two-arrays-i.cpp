class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {

        int n = nums.size();
        // if(n<2) return nums;
        vector<int> a{nums[0]}, b{nums[1]};
        // int c = a.size() - 1;
        // int d = b.size() - 1;

        for (int i = 2; i < n; i++) {
            if (a.back() > b.back())
                a.push_back(nums[i]);
            else if (a.back() < b.back())
                b.push_back(nums[i]);
            else
                a.push_back(nums[i]);
        }

        vector<int> ans;
        ans.insert(ans.end(), a.begin(), a.end());
        ans.insert(ans.end(), b.begin(), b.end());
        return ans;
    }
};