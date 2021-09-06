class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = releaseTimes.size();
        char ans = keysPressed[0];
        int maxi = releaseTimes[0];
        for(int i = 1;i < n; i++){
            int curr = releaseTimes[i]-releaseTimes[i-1];
            if(curr > maxi){
                maxi = curr;
                ans = keysPressed[i];
            }else if(curr == maxi && ans < keysPressed[i]){
				ans=keysPressed[i];
			}
        }
        return ans;
    }
};
