class Solution {
public:
    bool isSubstr(string& s1, string& s2){
        int i = 0, j = 0;
        while(i < s1.length() && j < s2.length()){
            if(s1[i] == s2[j]) j++;
            i++;
        }
        if(j == s2.length()) return true;
        return false;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string, bool> umap;
        int ans = 0;
        for(string& w : words){
            if(umap.find(w) == umap.end()) umap[w] = isSubstr(s, w);
            ans += umap[w];
        }
        return ans;
    }
};