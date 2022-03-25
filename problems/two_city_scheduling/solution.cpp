class Solution {
public:
    static bool com(int a,int b){
        return a>b;
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ans(0);
        vector<int>refund;
        for(auto it:costs){
            ans+=it[0];
            refund.push_back(it[0]-it[1]);
        }
        sort(begin(refund),end(refund),com);
        for(int i=0;i<(refund.size()/2);i++)ans-=refund[i];
        return ans;
    }
};
