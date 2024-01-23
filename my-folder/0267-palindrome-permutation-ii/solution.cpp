class Solution {
public:
    vector<string> res;
    unordered_map<char, int> mp;
    void backtracking(string s, string tmp) {
        if(s.length() == tmp.length()) {
            res.push_back(tmp);
            return;
        }

        for(auto it = mp.begin(); it != mp.end(); it++) {
            if(it->second) {
                it->second -=2;
                backtracking(s, it->first+tmp+it->first);
                it->second +=2;
            }
        }
    }
    vector<string> generatePalindromes(string s) {
        for(char c : s) mp[c]++;
        bool hasOdd = false;
        char odd;
        for(auto it : mp) {
            if(it.second % 2 == 1) {
                if(hasOdd) return res;
                else hasOdd = true, odd = it.first;
            } 
        }
        string start = "";
        if(hasOdd) {
            start += odd;
            mp[odd]--;
        }
        backtracking(s, start);
        return res;
    }
};
