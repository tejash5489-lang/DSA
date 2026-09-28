class Solution {
public:
    int maxDepth(string s) {
        int openbra = 0;
        int ans = 0;

        for (char& ch : s) {
            if (ch == '(')
                openbra++;
            else if (ch == ')')
                openbra--;

            ans = max(openbra, ans);
        }
        return ans;
    }
};