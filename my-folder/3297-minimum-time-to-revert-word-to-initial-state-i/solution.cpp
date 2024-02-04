class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int res = 0;
        string s = word;
        do{
            string tmp = s.substr(k);
            s = tmp;
            res++;
        } while(s.length() <= word.length() && s != word.substr(0, s.length()) && s.length() >= k);
        
        if(s !=  word.substr(0, s.length()) ) res++;
        // cout << s << endl;
        return res;
    }
};
