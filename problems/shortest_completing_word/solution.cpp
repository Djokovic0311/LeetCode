class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {        
        vector<int> mp(26,0);
        
        for(char ch : licensePlate)
            if(isalpha(ch)) mp[tolower(ch) - 'a']++; 
        
        string minLen;
        for(string word : words)
        {
            vector<int> temp = mp;
            for(char ch : word)
                temp[tolower(ch) - 'a']--;
            
            bool flag = true;
            for(int i : temp)
                if(i > 0) flag = false;
            
            if(flag && (minLen == "" || word.length() < minLen.length()))
                minLen = word;
        }
        
        return minLen;        
    }
};