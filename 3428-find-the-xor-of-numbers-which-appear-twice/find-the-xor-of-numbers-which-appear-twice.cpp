class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        map<int, int> mp;
        for (int x : nums) {
            mp[x]++;
        }
        int ans = 0;
        for (auto p : mp) {
            if (p.second == 2) {
                ans ^= p.first;
            }
        }
        return ans;
    }
};