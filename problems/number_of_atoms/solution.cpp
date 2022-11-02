class Solution {
public:
    string countOfAtoms(string formular) {
        string ans = "";
        map<string, int> mp;
        stack<int> stk;
        int cnt = 0, mult = 1;
        int n = formular.size();
        
        for(int i = n-1; i >= 0; i--) {
            if(isalpha(formular[i]) && islower(formular[i])) {
                int len = 2;
                i--;
                while(i >= 0 && islower(formular[i])) {
                    i--;
                    len++;
                }
                string atom = formular.substr(i, len);
                mp[atom] += max(cnt, 1) * mult;
                cnt = 0;
            } else if(isalpha(formular[i]) && isupper(formular[i])) {
                string atom(1, formular[i]);
                mp[atom] += max(1, cnt) * mult; 
                cnt = 0;
            } else if(isdigit(formular[i])) {
                cnt = formular[i] - '0';
                int p = 10;
                
                while (i - 1 >= 0 and isdigit(formular[i - 1])) {
                    cnt += p * (formular[--i] - '0');
                    p *= 10;
                }                
            } else if (formular[i] == ')') {
                stk.push(mult);
                mult *= max(cnt, 1);
                cnt = 0;
            } else {
                mult = stk.top();
                stk.pop();
            }
        
        }
        for (auto [atom, count]: mp) {
            ans += atom;
            
            if (count > 1) {
                ans += to_string(count);
            }
        }
        
        return ans;
    }
};