class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        vector<int> record(n+1,0);
        string s = "";
        vector<int> idx(n,0);
        for(int i = 0; i <n; i++) {
            
            if(nums[i] % p == 0)
                record[i] = 1;
            s += to_string(nums[i]);
            idx[i] = s.length();
            s += " ";
        }
        
        // inr res = 0;
        // cout <<idx[0]  << ' ';
        for(int i = 1; i < n; i++) {
            record[i] += record[i-1];
            // cout << idx[i] << ' ';
            // cout << record[i] << ' ';
        }
        // cout << endl;
        set<string> st;
        // cout << s<<endl;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int cnt = record[j] -record[i]  + (nums[i] % p == 0 ?1:0);
                if(cnt <= k){
                    string tmp = "";
                    // for(int k = i; k <= j; k++){
                    //     tmp += to_string(nums[k]) + " ";
                    //     // tmp += " ";
                    // }
                    // cout << idx[i]-to_string(nums[i]).length() << ' ' << idx[j]-idx[i]+to_string(nums[i]).length() << ' ';
                    tmp = s.substr(idx[i]-to_string(nums[i]).length(),idx[j]-idx[i]+to_string(nums[i]).length());
                    st.insert(tmp);
                    // cout << tmp << endl;
                }
                    
                
            }
        }
        // for(auto it = st.begin(); it != st.end(); it++)
        //     cout << *it << endl;
        return st.size();
    }
};
