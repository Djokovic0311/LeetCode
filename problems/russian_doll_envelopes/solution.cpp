class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
        
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        int i, j, n=envelopes.size();
        vector<int>lis;
        
        for(i=0; i<n; i++){
            // cout 
            auto it = lower_bound(lis.begin(), lis.end(), envelopes[i][1]);
            
            if(it==lis.end()){lis.push_back(envelopes[i][1]);}
            else{
                // cout << (*it) << endl;
                *it = envelopes[i][1];
            }
            // for(int x : lis) cout << x << ' ';
            // cout << endl;
        }
        return lis.size();
    }
};