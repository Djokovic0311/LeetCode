class Solution {
public:
static int cmp1(int a,int b)
{
    return b>a;
}

    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());
        int n = cost.size();
        if(n == 1) return cost[0];
        if(n == 2) return cost[1] + cost[0];
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(i %3 == 1 || i %3 == 0) {res += cost[i];    cout << cost[i] << ' ';}        
        }
        return res;
    }
};