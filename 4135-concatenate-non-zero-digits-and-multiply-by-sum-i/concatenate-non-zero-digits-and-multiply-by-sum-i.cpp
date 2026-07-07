class Solution {
public:
    long long sumAndMultiply(int n) {
        string x=to_string(n);
        string no="";
        int sum=0;
        for(auto ch:x){
            if(ch!='0'){
                no+=ch;
                sum+=ch-'0';
            }
        }
        if (no.empty())
        return 0;
        
        return stoll(no)*sum;
    }
};