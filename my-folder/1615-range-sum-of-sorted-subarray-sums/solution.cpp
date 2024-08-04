class Solution {
public:
    int rangeSum(vector<int>& v, int n, int left, int right) {
        vector<int>v1 ; 
        for(int i = 0 ; i < n; i++){
            long long curr = 0 ;
            for(int j = i ; j < n ; j++){
                curr += (v[j]);
                v1.push_back(curr) ;
            }

        }
        sort(v1.begin(),v1.end());
        long long sum = 0;
        cout<<v1.size() ;
        while(left <= right){
            if(right != left)
            sum += (v1[left - 1] + v1[right-1]) ;
            if(right == left) sum+=v1[left-1] ;
            right--;left++;
        }
        int res = sum % 1000000007;
        return res  ;
    }
};
