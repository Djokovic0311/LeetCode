class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int res = 0;
        int target = tickets[k];
        for(int i = 0; i<n; i++) {
            if(i <= k) {
                if(tickets[i] <= target) res += tickets[i];
                else res += target;
            }
            if(i > k) {
                res += min(target-1, tickets[i]);
            }
        }
        return res;
    }
};
