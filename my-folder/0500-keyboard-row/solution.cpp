class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> mp;
        vector<string> key = {"qwertyuiop","asdfghjkl","zxcvbnm"};
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < key[i].length(); j++)
                mp[key[i][j]] = i;
        }
        int n = words.size();
        vector<string> result;
        for(int i = 0; i < n; i++) {
            if(words[i].length() <= 1) result.push_back(words[i]);
            else{
                int tag = mp[tolower(words[i][0])];
                int j=1;
                
                while(j < words[i].length() && mp[tolower(words[i][j])] == tag) {
                    j++;

                }
                // cout << j << ' ';
                if(j == words[i].length())
                    result.push_back(words[i]);
            }
            
        }
        return result;
    }
};
