class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<=100;i++){
            int x=i;
            int product=1;

            while(x){
                int digit=x%10;
                product=digit*product;
                x/=10;
            }
            if(product%t==0) return i;
        }
        return -1;
    }
};