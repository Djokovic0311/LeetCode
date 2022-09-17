class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size(), m = trainers.size();
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int j = 0;
        int res = 0;
        for(int i = 0; i < n; i++) {
            // cout << i << endl;
            while(j < m && players[i] > trainers[j])
                j++;
            // while(j < m) {
            //     if(j < m && players[i] < trainers[j]) {
            //         res++;
            //     }
            // }
            if(j < m){
                res++;
                j++;
            }
                
        }
        return res;
    }
};
