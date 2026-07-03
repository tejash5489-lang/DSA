class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
        int i=0,j=0;
        map<string,int> mp;
        string curr="";
        vector<string> ans;

        while(j<n){
            curr+=s[j];
            while(j-i+1==10){
                if(mp[curr]==1){
                    ans.push_back(curr);
                }
                mp[curr]++;
                i++;
                curr.erase(0,1);
            }
            j++;
        }
        return ans;
    }
};