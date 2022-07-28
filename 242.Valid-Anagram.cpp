class Solution {
public:
    bool isAnagram(string a, string b) {
        if(a.length() != b.length()) return false;
        
        unordered_map<char, int> tmp;
        
        for(int i = 0; i < a.length(); ++i){
            tmp[a[i]]++;
            tmp[b[i]]--;
        }
        
        for(const auto& i : tmp){
            if(i.second != 0) 
                return false;
        }
        
        return true;
    }
};