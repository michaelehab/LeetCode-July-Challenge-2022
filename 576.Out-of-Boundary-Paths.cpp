class Solution {
    long long MOD = 1e9 + 7;
    vector<vector<vector<long long>>> memo;
public:
    long long rec(int m, int n, int maxMove, int startRow, int startColumn){
        if(startRow < 0 || startRow >= m || startColumn < 0 || startColumn >= n) return 1;
        if(!maxMove) return 0;
        if(memo[startRow][startColumn][maxMove] == -1){
            memo[startRow][startColumn][maxMove] = (
                rec(m, n, maxMove - 1, startRow - 1, startColumn) +
                rec(m, n, maxMove - 1, startRow + 1, startColumn) +
                rec(m, n, maxMove - 1, startRow, startColumn - 1) +
                rec(m, n, maxMove - 1, startRow, startColumn + 1)
            ) % MOD;
        }
        
        return memo[startRow][startColumn][maxMove];
        
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memo = vector<vector<vector<long long>>>(51, vector<vector<long long>>(51, vector<long long>(51, -1)));
        return rec(m, n, maxMove, startRow, startColumn) % MOD;
    }
};