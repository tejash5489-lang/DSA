class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            // ans[i]=sum;
        }

        int i=0;
        int count=0;
        long long l=0;  
        long long r=0;  
        while(i<n-1){
            l+=nums[i];
            r=sum-l;
            if(l>=r){
                count++;

            }
            i++;
        }
        return count;
    }
};