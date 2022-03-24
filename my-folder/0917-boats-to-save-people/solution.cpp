class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        int i = 0, j = n-1;
        int res = 0;
        while(i <= j) {
            int tmp = people[i] + people[j];
            if(tmp <= limit) {
                i++;
                j--;
            }
            else {
                j--;
            }
            res++;
        }
        return res;
    }
};
