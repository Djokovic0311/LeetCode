class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> result;
        int sum = 0;
        for(int& i:A){
            if(i%2==0)  sum += i;
        }
        for(int i=0;i<queries.size();i++){
            int temp = A[queries[i][1]];
            // if previous value was even, subtract it from sum
            if(temp % 2 == 0){
                sum -= temp;
            }
            A[queries[i][1]] += queries[i][0];
            // if nnew value is even, add this to sum
            if(A[queries[i][1]] % 2 == 0){
                sum += A[queries[i][1]];
            }
            // add sum to result
            result.push_back(sum);
        }
        return result;
    }
};