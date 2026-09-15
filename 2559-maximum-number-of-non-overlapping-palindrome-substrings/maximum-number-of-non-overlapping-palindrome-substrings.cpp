class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if (k == 1) 
            return n; //each character can be a substring

        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

        //Palindromic substring Blueprint
        for(int L = 1; L <= n; L++) {
            for(int i = 0; i+L <= n; i++) {
                int j = i + L - 1;

                if(i == j) {
                    isPalindrome[i][i] = true; //Single characters are palindrome
                } else if(i+1 == j) {
                    isPalindrome[i][j] = (s[i] == s[j]); //Strings of 2 Length
                } else {
                    isPalindrome[i][j] = ((s[i] == s[j]) && isPalindrome[i+1][j-1] == true);
                }
            }
        }

        vector<vector<int>> t(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= i; --j) {

                if (isPalindrome[i][j]) {
                    int growWindow  = t[i][j + 1];
                    int takeIt      = 1 + (j + k <= n ? t[j + 1][j + k] : 0);
                    int slideWindow = t[i + 1][j + 1];

                    t[i][j] = max({growWindow, takeIt, slideWindow});
                }
                
                int slideWindow = t[i + 1][j + 1];
                int growWindow  = t[i][j + 1];
                t[i][j] = max({t[i][j], slideWindow, growWindow});
            }
        }

        return t[0][k - 1];
    }
};