class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int a = s1.size(), b = s2.size(), c = s3.size();
        if (a + b != c) return false;
        vector<vector<bool>> dp(a + 1, vector<bool>(b + 1, false));
        for (int i = 0; i <= a; ++i) {
            for (int j = 0; j <= b; ++j) {
                if (!i && !j) dp[i][j] = true;
                else if (!i) dp[i][j] = dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]);
                else if (!j) dp[i][j] = dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1]);
                else dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dp[a][b];
    }
};