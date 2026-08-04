class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> st;
        int mini=INT_MAX,maxi=INT_MIN;
        for(int x:nums){
            st.insert(x);
            mini=min(mini,x);
            maxi=max(maxi,x);
        }

        for(int i=mini;i<=maxi;i++){
            if(!st.count(i)) ans.push_back(i);
        }
        return ans;
    }
};