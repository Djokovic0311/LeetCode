        typedef pair <int ,int> ipair;
class Solution {
public:

        vector <ipair> temp;
        void merge(vector <ipair> &vec , int st , int mid , int end , vector <int> &ans){
        int rc = 0 , l = st , r = mid + 1  , idx = st;
        while(l <= mid && r <= end){
            if(vec[l].first > vec[r].first){
                temp[idx] = vec[r];
                rc++ , r++;
            }
            else{
                ans[vec[l].second] += rc;
                temp[idx] = vec[l];
                l++;
            }
            idx++;
        }
        while(l <= mid){
            ans[vec[l].second] += rc;
            temp[idx] = vec[l];
            l++ , idx++;
        }
        while(r <= end){
            temp[idx] = vec[r];
            rc++ , r++ , idx++;
        }
        for(int i = st ; i <= end ; i++){
            vec[i] = temp[i];
        }
    }


    void mergesort(vector <ipair> &vec , int st , int end , vector <int> &ans){
        if(st >= end)
            return ;
        int mid = st + (end-st)/2;
        mergesort(vec ,  st , mid  , ans );
        mergesort(vec , mid +1 , end , ans);
        merge(vec , st , mid , end , ans);
    }

    vector <int> countsmaller(vector <int> &nums){
        int n = nums.size();
        temp.resize(n);
        vector < ipair > pairs;
        for(int i = 0 ; i < nums.size() ; i++){
            pairs.push_back({nums[i] , i});
        }
        vector <int> ans(n);
        mergesort(pairs , 0 , n-1 , ans);
        return ans;
    }
    long long goodTriplets(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_map <int,int> umap;
        for(int i = 0 ; i < B.size(); i++)
            umap[B[i]] = i;

        for(auto &val : A){
            val = umap[val];                 
        }
        vector <int> ans = countsmaller(A);  
        long long res =  0;
        for(int i =0; i < A.size() ; i++){
            int rightelements  = n - i -1 ;
            long long rightgreater   = (rightelements - ans[i]);
            int leftelements   = i;
            long long leftsmaller    = A[i] - ans[i];

            res += (rightgreater * leftsmaller);
        }
        return res;
        
    }
};
