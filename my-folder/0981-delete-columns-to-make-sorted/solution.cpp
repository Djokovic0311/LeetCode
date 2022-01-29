class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cnt = 0;
        
        for(int i=0; i<strs[0].length(); i++){
            bool flag = false;
            for(int j=1; j<strs.size(); j++){
                if(strs[j][i] < strs[j-1][i])
                    flag = true;
            }
            if(flag)
                cnt++;
        }
        return cnt;        
    }
};
