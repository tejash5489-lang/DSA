class Solution {
public:
    int maxProduct(int n) {
        int first = 0, sec = 0;

        while (n > 0) {
            int lsd = n % 10;
            if (first <= lsd) {
                sec = first;
                first = lsd;
            } else if (lsd > sec) {
                sec = lsd;
            }

            n /= 10;
        }
        return first * sec;
    }
};