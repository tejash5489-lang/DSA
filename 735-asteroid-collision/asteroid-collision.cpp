class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;

        for (int& a : asteroids) {
            while (a < 0 && !s.empty() && s.top() > 0) {
                int sum = a + s.top();

                if (sum < 0) {
                    s.pop();
                } else if (sum > 0) {
                    a = 0;
                } else {
                    s.pop();
                    a = 0;
                }
            }
            if (a != 0)
                s.push(a);
        }

        int n = s.size() - 1;
        vector<int> ans(n + 1);

        while (!s.empty()) {
            ans[n] = s.top();
            s.pop();
            n--;
        }
        return ans;
    }
};