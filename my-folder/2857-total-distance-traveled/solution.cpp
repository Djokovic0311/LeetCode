class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int res = 0;
        while(mainTank > 0) {
            // cout << res << endl;

            if(mainTank >= 1) {
                mainTank -= 1;
                res += 1;
            }
            if(res != 0 && res % 5 == 0 && additionalTank >= 1) {
                // cout << " yes" << endl;
                mainTank += 1;
                additionalTank -= 1;
            }
        }
        
        return res * 10;
    }
};
