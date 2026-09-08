class Solution {
public:
    int countCommas(int n) {
        int ans=0;
        if(n>999){
            int l=n-999;
            ans=l;
        }
        return ans;
    }
};