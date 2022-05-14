class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int res = 0;
        int cnt = 0;
        string tmp = "";
        string n = to_string(num);
        for(int i = 0; i < n.length(); i++) {
            if(cnt < k) {
                tmp += n[i];
                cnt++;
            }
            else if(cnt == k){
                int t = stoi(tmp);
                
                if(t != 0 && num % t == 0) {
                    res++;
                    
                }
                tmp = tmp.substr(1) + n[i];
                // cout << tmp << endl;
            }
        }
        if(stoi(tmp) != 0 && num % stoi(tmp) == 0) res++;
        return res;
    }
};