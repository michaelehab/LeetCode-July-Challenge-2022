class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans = 0, m = matrix.size(), n = matrix[0].size();
		for (int i = 0; i < m; i++)
			for (int j = 1; j < n; j++)
				matrix[i][j] += matrix[i][j - 1];

		unordered_map<int, int> counter;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				counter = {{0,1}};
				int curr = 0;
				for (int k = 0; k < m; k++) {
				  curr += matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0);
				  ans += counter.find(curr - target) != counter.end() ? counter[curr - target] : 0;
				  counter[curr]++;
				}
			}
		}
		return ans;
    }
};