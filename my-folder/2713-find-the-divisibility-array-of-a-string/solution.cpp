class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        long long curr = 0;
        
        int n = word.length();
        vector<int> res(n,0);
        
        for(int i = 0; i < n; i++) {
            // cout << word[i]-'0' <<endl;
            long long mod = (word[i]-'0') % m;
            // cout << mod << " " ;
            // cout << curr << endl;
            if(mod == 0 && i == 0) {
                res[i] = 1;
                curr = mod;
            } 
            else if(mod == 0 && curr == 0) {
                res[i] = 1;
            }
            else if(mod != 0 && curr == 0) {
                curr += mod;
            }
            else if(curr != 0) {

                curr = (curr*10 + mod) % m;
                // cout << i ;
                if(curr == 0) res[i] = 1;
            }

        }
        return res;
    }
};
