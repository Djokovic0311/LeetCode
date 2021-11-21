class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int begin = 0, end = 0;
        if(n == 1) return 1;
        int res = 0;
        while(end < n) {
            int tmp = 0;
            end = begin;
            tmp = plants[begin];
            while(tmp <= capacity && end < n-1){
                end++;
                tmp += plants[end];
            }

            if(tmp > capacity) {res += end*2; end--;}
            else res += end + 1;
            cout << begin <<endl;
            cout << end << endl;
            if(end == n-1) break;
            begin = end+1;
        }
        // cout << begin <<endl;
        // cout << end << endl;
        cout<<res;
        return res;
    }
};
