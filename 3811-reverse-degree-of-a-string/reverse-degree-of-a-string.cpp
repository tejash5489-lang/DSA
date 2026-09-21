class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++){
            int num = 'z'-s[i]+1;
            sum += ((i+1)*num);
        }
        return sum;
    }
};