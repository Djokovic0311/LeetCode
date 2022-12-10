class Solution {
public:
    void backtracking(int& lastpos, int& lastneg, int& curpos, vector<int>& stones, int& res) {
        int n = stones.size();
        if(curpos == n - 1) {
            return;
        }
        for(int idx = curpos; idx < n; idx++) {
            cout << lastpos << ' ' << lastneg << ' ' << res << endl;
            for(int i = 0; i < 2; i++) {
                if(i == 0) {
                    res = max(res, stones[idx] - stones[lastpos]);
                    int tmp = lastpos;
                    lastpos = idx;
                    idx++;
                    backtracking(lastpos, lastneg, idx, stones, res);
                    idx--;
                    lastpos = tmp;
                
                }
                else {
                    res = max(res, stones[idx] - stones[lastneg]);
                    int tmp = lastneg;
                    lastneg = idx;
                    idx++;
                    backtracking(lastpos, lastneg, idx, stones, res);
                    idx--;
                    lastneg = tmp;
                }
            }            
        }

    }
    int maxJump(vector<int>& stones) {
        int res = stones[1]-stones[0]; // store max difference
        for(int i = 3; i < stones.size(); i+=2) res = max(res, stones[i]-stones[i-2]); // odd path
        for(int i = 2; i < stones.size(); i+=2) res = max(res, stones[i]-stones[i-2]); // even path
        return res;
    }
};
