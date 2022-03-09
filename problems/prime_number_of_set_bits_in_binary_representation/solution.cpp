class Solution {
public:
    int findSetBits(int n){
        int count=0;
        while(n){
            n=n&(n-1);
            count++;
        }
        return count;
    }
    bool checkPrime(int x){
        return (x == 2 || x == 3 || x == 5 || x == 7 ||
                x == 11 || x == 13 || x == 17 || x == 19);
    }
    int countPrimeSetBits(int left, int right) {
        int res = 0;
        for(int i = left; i <= right; i++) {
            if(checkPrime(findSetBits(i))) res++;
        }
        return res;
    }
};