class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> dic(26,0);
        for(char c : chars) {
            dic[c-'a']++;
        }
        int res = 0;
      for (auto &w : words) {
        int cnt1[26] = {}, match = true;
        for (auto ch : w)
          if (++cnt1[ch - 'a'] > dic[ch - 'a']) {
            match = false;
            break;
          }
        if (match) 
            res += w.size();
      }
      return res;
    }
};
