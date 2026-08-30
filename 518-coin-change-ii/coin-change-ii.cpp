class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<int> curr(amount + 1, 0);
        vector<int> next(amount + 1, 0);

        next[0] = 1;

        for (int i = n - 1; i >= 0; i--) {

            curr[0] = 1;

            for (int j = 1; j <= amount; j++) {

                long long skip = next[j];

                long long take = 0;
                if (j >= coins[i]) {
                    take = curr[j - coins[i]];
                }

                curr[j] = take + skip;
            }

            next = curr;
        }

        return curr[amount];
    }
};