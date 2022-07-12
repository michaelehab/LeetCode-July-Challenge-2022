class Solution {
public:
    bool flag = 0;
    int side;
    void rec(vector<int>&ms, int i, int a, int b, int c, int d){  
        if(flag) return;
        if(i == ms.size() && a == side && b == side && c == side && d == side) flag = true;
        else{
            if(a + ms[i] <= side) 
                rec(ms, i + 1, a + ms[i], b, c, d);
            if(b != a && b + ms[i] <= side) 
                rec(ms, i + 1, a, b + ms[i], c, d);
            if(c != b && c != a && c + ms[i] <= side) 
                rec(ms, i + 1, a, b, c + ms[i], d);
            if(d != a && d != b && d != c && d + ms[i] <= side) 
                rec(ms, i + 1, a, b, c, d + ms[i]);
        }
    }
    
    bool makesquare(vector<int>& ms) {
        long long sum = accumulate(ms.begin(), ms.end(), 0);
        if(sum % 4 != 0) return false;
        side = sum / 4;
        sort(ms.begin(), ms.end(), greater<int>());
        if(ms.back() > side) return false;
        rec(ms, 0, 0, 0, 0, 0);
        return flag;
    }
};