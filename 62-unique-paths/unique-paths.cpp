class Solution {
public:
    int uniquePaths(int m, int n) {
        int* row = new int [n];
        fill_n(row, n, 1);
        for (int i = 0; i < m - 1; i++)
            for (int j = n - 2; j >= 0; j--)
                row[j] = row[j] + row[j+1];
        return row[0];
    }
};