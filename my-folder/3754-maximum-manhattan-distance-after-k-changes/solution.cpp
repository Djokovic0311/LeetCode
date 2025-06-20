class Solution {
public:
    int count(int drt1, int drt2, int times) {
        return abs(drt1 - drt2) + times * 2;
    }
    int maxDistance(string s, int k) {
        int res = 0;
        int north = 0, south = 0, east = 0, west = 0;
        for(char c : s) {
            switch (c) {
                case 'N':
                    north++;
                    break;
                case 'S':
                    south++;
                    break;
                case 'W':
                    west++;
                    break;
                case 'E':
                    east++;
                    break;
            }
            int t1 = min({north, south, k});
            int t2 = min({east, west, k - t1});
            res = max(res, count(north, south, t1)+count(east, west, t2));
        }
        return res;
    }
};
