class Solution {
public:
    long long longestConsecutive(vector<int>& nums) {
        unordered_set <long long> s(nums.begin(), nums.end());
        long long n = nums.size(), i = 0, mx = 0;
        while(i < n){
            // Checking if the current element is a start
            if(s.find(nums[i] - 1) == s.end()){
                long long sz = 1, nxt = nums[i] + 1;
                bool finished_seq = false;
                while(!finished_seq){
                    if(s.find(nxt) != s.end()) sz++, nxt++;
                    else finished_seq = true;
                }
                mx = max(mx, sz);
            }
            i++;
        }
        return mx;
    }
};