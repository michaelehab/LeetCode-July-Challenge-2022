class Solution {
public:
    int findPos(vector<int>& nums, int start, int target, bool first){
        if(start == -1) return -1;
        
        int pos = -1, end = nums.size() - 1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(nums[mid] == target){
                pos = mid;
                if(first) end = mid - 1;
                else start = mid + 1;
            }
            else if(nums[mid] > target) end = mid - 1;
            else start = mid + 1;
        }
        return pos;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int firstPos = findPos(nums, 0, target, true);
        ans.push_back(firstPos);
        ans.push_back(findPos(nums, firstPos, target, false));
        return ans;
    }
};