class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 2;
        int res = 0;
        vector<int> v;
        int cur = nums[0];
        v.push_back(cur);
        for(int i = 1; i < n; i++) {
            if(nums[i] != cur) {
                v.push_back(nums[i]);
                cur = nums[i];
                }
        }
        for(int i = 0; i < v.size(); i++) {
            cout << v[i] << ' ';
        }
        cout << endl;
        for(int i = 1; i < v.size()-1; i++) {
            if(v[i] == v[i-1]) continue;
            l = i-1;
            while(r < n && v[r] == v[i]) {
                r++;
            }
            if(r == n) break;
            while(l >= 0 && v[l] == v[i]) {
                l--;
            }
            if(l == -1) continue;
            cout << l << ' ' << r << endl;
            cout << i << endl;
            
            if((v[i] > v[l] && v[i] > v[r])||(v[i] < v[l] && v[i] < v[r])){
                res++;
                cout << i << ' ';
            }
                
        }
        cout << endl;
        return res;
    }
};
