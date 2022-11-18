class Solution {
public:
    string countOfAtoms(string formula) {
        string ans = "";
        map<string, int> mp;
        stack<int> stk;
        int cnt = 0, mult = 1;
        int n = formula.length();

        for(int i = n-1; i >= 0; i--) {
            char c = formula[i];
            if(isalpha(c) && islower(c)) {
                int len = 2;
                i--;
                while(isalpha(formula[i]) && islower(formula[i])) {
                    i--;
                    len++;
                }
                string name = formula.substr(i, len);
                mp[name] += max(1, cnt) * mult;
                cnt = 0;
            }
            else if(isalpha(c) && isupper(c)) {
                string atom(1, c);
                mp[atom] += max(1, cnt) * mult; 
                cnt = 0;                
            }
            else if(isdigit(c)) {
                cnt = c - '0';
                int p = 10;
                while(i-1 >= 0 && isdigit(formula[i-1])) {
                    cnt += p * (formula[--i] - '0');
                    p *= 10;
                }
            }
            else if(c == '(') {
                mult = stk.top();
                stk.pop();
            }
            else {
                stk.push(mult);
                mult *= max(cnt, 1);
                cnt = 0;
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
