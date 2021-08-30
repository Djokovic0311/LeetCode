class Solution {
public:
    int majorityElement(vector<int>& a) {
        int ans = a[0];
        int n = a.size();
        int cnt = 1;
        for(int i = 1; i < n; i++){
            if(a[i] == ans){
                cnt++;
            } else{
                cnt--;
            }
            if(cnt < 0) {
                cnt = 0;
                ans = a[i];
            }
        }
        return ans;
    }
};