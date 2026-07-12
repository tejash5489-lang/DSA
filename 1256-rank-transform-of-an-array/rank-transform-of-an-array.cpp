class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        auto last = unique(temp.begin(), temp.end());
        temp.erase(last, temp.end());
        unordered_map<int, int> mp;
        for (int i = 0; i < temp.size(); i++) {
            mp[temp[i]] = i + 1;
        }
        for (int i = 0; i < n; i++) {
            ans.push_back(mp[arr[i]]);
        }
        return ans;
    }
};