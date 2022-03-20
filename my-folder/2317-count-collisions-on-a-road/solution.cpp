class Solution {
public:
    bool c1(char A, char B) {
        return (A == 'R' && B == 'L');
    }
    bool c2(char A, char B) {
        return (A == 'R' && B == 'S') || (A == 'S' && B == 'L');
    }
    int countCollisions(string dir) {
        int res(0), n(size(dir)), i(0), carsFromRight(0);
        
        while (i < n and dir[i] == 'L') i++; // skipping all the cars going to left from beginning as they will never collide
        
        for ( ; i<n; i++) {
            if (dir[i] == 'R')  carsFromRight++;
            else {
                res += (dir[i] == 'S') ? carsFromRight : carsFromRight+1;
                
                carsFromRight = 0;
            }
        }
        return res;
    } 
};
