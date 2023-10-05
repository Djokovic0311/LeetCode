class Solution {
public:
    vector<int> solve(vector<int>& res, vector<int>& used, int index){
        if(index == res.size()){
            return res;
        }
        // position used, go to next index
        if(res[index] != 0){
            return solve(res, used, index+1);
        }
        // from n to 1
        for(int i=used.size()-1; i>=1; i--){
            // number used
            if(used[i] == 0){
                continue;
            }
            int dist = (i == 1) ? 0 : i;
            if(index + dist < res.size() && res[index + dist] == 0){
                res[index] = res[index + dist] = i;
                used[i] = 0;
                vector<int> temp = solve(res, used, index+1);
                if(!temp.empty()){
                    return temp;
                }
                used[i] = 1;
                res[index] = res[index + dist] = 0;
            }
        }
        return {};
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> res(2*n-1, 0), used(n+1, 1);
        return solve(res, used, 0);
    }
};
