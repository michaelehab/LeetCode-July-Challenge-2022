class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long long vertical = 0, horizontal = 0;
        long long MOD = 1e9 + 7;
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        vertical = max(horizontalCuts[0], h - horizontalCuts[horizontalCuts.size() - 1]);
        for(int i = 1; i < horizontalCuts.size(); ++i) 
            vertical = max(vertical, (long long)(horizontalCuts[i] - horizontalCuts[i - 1])) % MOD;
            
        sort(verticalCuts.begin(), verticalCuts.end());
        horizontal = max(verticalCuts[0], w - verticalCuts[verticalCuts.size() - 1]);
        for(int i = 1; i < verticalCuts.size(); ++i) 
            horizontal = max(horizontal, (long long)(verticalCuts[i] - verticalCuts[i - 1])) % MOD;
            
        return (horizontal * vertical) % MOD;
    }
};