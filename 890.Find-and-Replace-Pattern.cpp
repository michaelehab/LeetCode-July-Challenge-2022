class Solution {
public:
    bool isPattern(string pattern, string word){
        if(pattern.length() != word.length()) return false;
        unordered_map<char, char> umap;
        vector<bool> map_to(26, false);
        for(int i = 0; i < word.length(); ++i){
            if(umap.find(word[i]) == umap.end() && !map_to[pattern[i] - 'a']){
                umap[word[i]] = pattern[i];
                map_to[pattern[i] - 'a'] = true;
            }
            else if(umap.find(word[i]) != umap.end() && umap[word[i]] == pattern[i]) continue;
            else return false;
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(string s : words){
            if(isPattern(pattern, s)) 
                ans.push_back(s);
        }
        return ans;
    }
};