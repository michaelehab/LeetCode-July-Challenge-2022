class Solution {
    long long MOD = 1e9 + 7;
public:
    int kInversePairs(int n, int K) {
        vector<vector<int>> dp(1001, vector<int>(1001));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i){
            long long tmp = 0;
            for (int j = 0; j <= K; ++j){
                tmp += dp[i - 1][j];
                if (j >= i) tmp -= dp[i - 1][j - i];
                dp[i][j] = (dp[i][j] + tmp) % MOD; 
            }
        }
        return dp[n][K];
    }
};