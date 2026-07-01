class Solution {
public:
    bool check(string& word1, string& word2) {
        vector<int> v(26, 0);

        for (char& ch : word1)
            v[ch - 'a']++;

        for (char& ch : word2)
            v[ch - 'a']--;

        for (int i = 0; i < 26; i++) {
            if (v[i] != 0)
                return false;
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();

        vector<string> result;

        result.push_back(words[0]);

        for (int i = 1; i < n; i++) {
            if (!check(words[i], result.back()))
                result.push_back(words[i]);
        }
        return result;
    }
};