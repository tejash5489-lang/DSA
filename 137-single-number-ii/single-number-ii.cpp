class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i <= 31; i++) {
            int temp = 1 << i;
            int countones = 0;
            for (int& num : nums) {
                if ((num & temp) == 0) {

                } else {
                    countones++;
                }
            }
            if (countones % 3 == 1) {
                ans = (ans | temp);
            }
        }
        return ans;
    }
};