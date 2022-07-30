class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        
        vector<int> freq(26, 0);
        for(const string& word : words2){
            vector<int> tmp(26, 0);
            for(const char& c : word) tmp[c - 'a']++;
            for(int i = 0; i < 26; ++i) freq[i] = max(freq[i], tmp[i]);
        }
        
        for(const string& word : words1){
            vector<int> tmp(26, 0);
            for(const char& c : word) tmp[c - 'a']++;
            bool flag = true;
            for(int i = 0; i < 26; ++i) if(freq[i] > tmp[i]) flag = false;
            if(flag) ans.push_back(word);
        }
        
        return ans;
    }
};