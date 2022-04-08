class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int k) {
        
        vector <vector <double>> t(A.size() + 1, vector <double>(A.size() + 1, -1.00));
        
        double ans = solve(A, k, 0, t);
        
        return ans;
    }
    
    double solve(vector <int>& A, int k, int start, vector <vector <double>>& t)
    {
        if(k <= 0)       // Base condition
            return 0;  
        
        if(t[k][start] != -1.00)
            return t[k][start];   // Memo
        
        double res = 0.00;
        double sum = 0.00;
        
        for(int i = start; i < A.size(); i++)    // Different indices that we can break at.
        {
            sum += A[i];  // Sum till the particular index
            
            if(k != 1 || i == A.size() - 1)
                res = max(res, sum / (i - start + 1) + solve(A, k - 1, i + 1, t)); // recursive call
        }
        
        return t[k][start] = res;
    }
};
