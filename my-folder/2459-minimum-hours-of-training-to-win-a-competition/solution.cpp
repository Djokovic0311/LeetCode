class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int res = 0;
        int n = energy.size();
        int totalenergy = 0;
        for(int e : energy) {
            totalenergy += e;
        }
        if(initialEnergy <= totalenergy)
            res = totalenergy - initialEnergy + 1;
        int ex = experience[0];
        int tmpex = ex;
        for(int i = 1; i < n; i++) {
            
            ex = max(ex, experience[i]-tmpex);
            tmpex += experience[i];
        }
        if(ex >= initialExperience)
            res += ex-initialExperience+1;
        return res;
    }
};
