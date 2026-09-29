class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        unordered_map<string, function<int(int, int)>> mp = {
            {"+", [](int a, int b) { return a + b; }},
            {"-", [](int a, int b) { return a - b; }},
            {"*", [](int a, int b) { return (long)a * (long)b; }},
            {"/", [](int a, int b) { return a / b; }},
        };

        for (string& token : tokens) {
            if (token == "+" || token == "*" || token == "-" || token == "/") {
                int b = s.top();
                s.pop();

                int a = s.top();
                s.pop();

                int ans = mp[token](a, b);

                s.push(ans);
            } else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};