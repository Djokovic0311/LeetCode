class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        vector<int> res(n,0);
        sort(potions.begin(),potions.end());
        cout << m<<endl;
        for(int i = 0; i < n; i++) {
            long long target = (success%spells[i]==0)?success/spells[i]:success/spells[i]+1;
            
            res[i] = m-(lower_bound(potions.begin(),potions.end(),target)-potions.begin());
            if(res[i]>n){
                cout << i << ' ' << lower_bound(potions.begin(),potions.end(),target)-potions.begin();
                // res[i]=0;
            } 
        }
        return res;
    }
};
