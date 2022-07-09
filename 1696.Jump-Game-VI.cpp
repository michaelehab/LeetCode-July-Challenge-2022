class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>dp(n, -1e9);
        deque<int> dq = {0};
        dp[0] = nums[0];
        for(int i = 1; i < n; ++i){
            if(dq.front() < i - k) dq.pop_front();
            dp[i] = nums[i] + dp[dq.front()];
            while(!dq.empty() && dp[dq.back()] <= dp[i]) dq.pop_back();
            dq.push_back(i);
        }
        return dp.back();
    }
};