class Solution {
public:
    
    struct segmentTree{
        static constexpr int unit = 0;
        int merge(int a, int b) {
             return a + b; 
        }

        vector<int> t;
        int n;
        
        segmentTree(int n = 0, int def = unit){
            t = vector<int>(2 * n, def);
            this->n = n;
        }

        void update(int pos, int val){
            pos += n;
            t[pos] += val;

            for (pos = pos / 2; pos > 0; pos /= 2){
                t[pos] = merge(t[pos * 2], t[pos * 2 + 1]);
            }
        }
        
        int query(int b, int e){
            int ra = unit, rb = unit;
            for (b += n, e += n; b < e; b /= 2, e /= 2){
                if (b % 2) ra = merge(ra, t[b++]);
                if (e % 2) rb = merge(t[--e], rb);
            }
            return merge(ra, rb);
        }
    };
    
    int retval(int a){
        return a + 10000;
    }
    
    
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        int a = retval(nums[0]);
        
        for(int i = 0; i < n; ++i){
            nums[i] = retval(nums[i]);
            a = max(a, nums[i]);
        }
        
        segmentTree t(a + 1, 0);
        vector<int> ans(n);
        
        int mn = nums[n - 1];
        for(int i = n - 1; i >= 0; --i){
            t.update(nums[i], 1);
            mn = min(mn, nums[i]);
            ans[i] = (mn < nums[i]) ? t.query(mn, nums[i]) : 0;
        }
        
        return ans;
    }
};