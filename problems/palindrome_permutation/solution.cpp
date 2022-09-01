class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int>hash(26,0);
        int flag{0};
        
        for(auto x:s)
        {
            hash.at(x-'a')++;
        }
        for(auto x:hash)  if(x%2 == 1) flag++;
        
        if(s.size() % 2 ==1)
        {
            if(flag == 1) return 1;
            else return 0;
        }
        
        return flag == 0;
    }
};