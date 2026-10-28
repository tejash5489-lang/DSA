class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string fr(n, '.');
        string orr (n, '#');

        orr [n - 1] = '.';

        vector<string> grid(m, orr);

        grid[0] = fr;

        return grid;
    }
};