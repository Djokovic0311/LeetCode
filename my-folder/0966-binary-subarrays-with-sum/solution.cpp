class Solution {
public:
    int atMost(vector<int>& A, int S) {
        int i=0,j=0,count=0,sum=0;
        int size=A.size();
        if (S < 0)return 0;

        while(j<size){
            sum+=A[j];
            while(sum>S ){
                sum-=A[i];
                i++;
            }
            count+=j-i+1;
            j++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& A, int S) {
         return atMost(A, S) - atMost(A, S - 1);

    }
};
