class Solution {
public:
    set<int> st;
    void primeFactors(int n)
    {
        // Print the number of 2s that divide n

        while (n % 2 == 0)
        {
            st.insert(2);
             // cout << 2 << " ";
            n = n/2;
        }

        // n must be odd at this point. So we can skip
        // one element (Note i = i +2)
        for (int i = 3; i <= sqrt(n); i = i + 2)
        {
            // While i divides n, print i and divide n
            while (n % i == 0)
            {
                st.insert(i);
                cout << st.size() << endl;
                // cout << i << " ";
                n = n/i;
            }
        }
            if (n > 2)
                st.insert(n);
        // cout << n << " ";
        // cout << endl;
        
        }       
 
    int distinctPrimeFactors(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        
        for(int num : nums) {
            primeFactors(num);
        }
        return st.size();
    }
};
