class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        
        vector<int> fib;

        int a=0;
        int b=1;
        int c=a+b;

        fib.push_back(a);
        fib.push_back(b);
        
        while(c<=k)
        {
            fib.push_back(c);
            a=b;
            b=c;
            c= a+b;
        }

        int count=0;
        int size = fib.size();
        int i =0;

        while(k)
        {
            if(fib[size-1-i]<=k)
            {
                count++;
                k-=fib[size-1-i];
            }
            else if(fib[size-1-i]>k) i++;
        }

        return count;        
    }
};
