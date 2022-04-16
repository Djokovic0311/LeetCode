class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long res = 0;
        if(cost1 < cost2) {
            int tmp = cost1;
            cost1 = cost2;
            cost2 = tmp;
        }
        int mx_cost1 = total / cost1;
        for(int i = 0; i <= mx_cost1; i++) {
            res += (total/cost2)+1;
            total -= cost1;
            // cout << i << ' ' << res << ' ' <<total <<endl;
            // cout << res <<endl;
            // cout << total << endl;
        }
        return res;
    }
};