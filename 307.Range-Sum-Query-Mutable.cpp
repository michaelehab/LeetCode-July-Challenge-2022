class NumArray {
    vector<int> segTree;
    vector<int> arr;
    int n;
    
    void build(int l, int r, int ind){
        if(l == r) segTree[ind] = arr[l];
        else{
            int mid = l + (r - l) / 2;
        
            build(l, mid, 2*ind + 1);
            build(mid + 1, r, 2*ind + 2);

            segTree[ind] = segTree[2*ind + 1] + segTree[2*ind + 2];
        }
    }
    
    int query(int l, int r, int i, int j, int ind){
        if(l >= i && r <= j) return segTree[ind];
        
        if(r < i || l>j) return 0;
        
        int mid = l + (r - l) / 2;
        
        return query(l, mid, i, j, 2*ind + 1) + query(mid + 1, r, i, j, 2*ind + 2);
    }
    
    void update(int l, int r, int diff, int i, int ind){
        if(i >= l && i <= r){
            segTree[ind] += diff;
            
            if(l != r){
                int mid = l + (r - l) / 2;
                update(l, mid, diff, i, 2*ind + 1);
                update(mid+1, r, diff, i, 2*ind + 2);
            }
        }
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        arr = nums;
        segTree = vector<int>(4 * n);
        build(0, n - 1, 0);
    }
    
    void update(int index, int val) {
        int diff = val - arr[index];
        arr[index] = val;
        update(0, n - 1, diff, index, 0);
    }
    
    int sumRange(int left, int right) {
        return query(0, n - 1, left, right, 0);
    }
};

/**
 * Your NumArray object will be insegTreeantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */