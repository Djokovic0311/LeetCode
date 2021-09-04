class Solution {
public:
    int countPrimes(int n) {
        int count=0;
        vector<bool> primes(n,true);
        for(int i=2; i*i<n; i++)
        {
            if(primes[i])
            {
                for(int j=i*i; j<n; j+=i)
                {
                    primes[j]=false;
                }
            }
        }
        for(int i=2; i<n; i++)
        {
            if(primes[i])
                count++;
        }
        return count;
    }
};