class Solution {
public:
    int helper(vector<int>& v, int n) {
        int mx = v[0], mi = v[0];
        for(int i = 0; i < n; i++) {
            mx = max(mx, v[i]);
            mi = min(mi, v[i]);
        }
        return (mx - mi);
    }
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        vector<int> sum1(n,0),diff1(n,0),sum2(n,0),diff2(n,0);
        for(int i=0;i<n;i++) {
            sum1[i]=arr1[i]+arr2[i]+i;
            diff1[i]=arr1[i]-arr2[i]+i;
            sum2[i]=arr1[i]+arr2[i]-i;
            diff2[i]=arr1[i]-arr2[i]-i;
        }
        return max(max(helper(sum1,n),helper(diff1,n)),max(helper(sum2,n),helper(diff2,n)));  
    }
};
