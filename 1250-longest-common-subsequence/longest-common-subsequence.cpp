class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int** mapper = new int*[text1.length() + 1];
        for (int i = 0; i < text1.length() + 1; i++)
        {
            mapper[i] = new int[text2.length() + 1];
            fill_n(mapper[i], text2.length() + 1, 0);
        }
        for (int i = text1.length() - 1; i >=0 ; i--)
            for (int j = text2.length() - 1; j >=0 ; j--)
                if(text1[i] == text2[j]){
                    mapper[i][j] = 1 + mapper[i+1][j+1];
                }
                else{
                    mapper[i][j] = max(mapper[i+1][j], mapper[i][j+1]);
                }
        return mapper[0][0];
    }
};