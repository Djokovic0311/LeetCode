class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n = forts.size();
        int res = 0;
        
        int flag = 0;
        int pre = 0;
        for(int i = 0; i < n; i++) {
            if(abs(forts[i]) == 1) {
                if(flag == 0) {
                    flag = forts[i];
                    pre = i;
                }
                else if(flag == (-1) * forts[i]){
                    flag = forts[i];
                    res = max(res, i-pre-1);
                    pre = i;
                }
                else {
                    flag = forts[i];
                    pre = i;
                }
            }
            
            // cout << flag << " " << pre << "  " << i <<endl;
        }
        return res;
    }
};
