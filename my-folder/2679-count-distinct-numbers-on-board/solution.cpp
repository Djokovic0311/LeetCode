class Solution {
public:
    int distinctIntegers(int n) {
        unordered_set<int> st, curr;//curr -> st
        st.insert(n);
        
        
        while(curr.size() != st.size()) {
            curr = st;
            
            for(int i = 1; i <= n; i++) {
                for(int p : curr) {
                    if(p %i==1){
                        // cout << i << ' ' << p << endl;
                        st.insert(i);
                    }                    
                }

            }
            
        }
        
        // for(int m : curr) {
        //     cout << m << ' ';
        // }
        // cout << endl;
        return int(curr.size());
    }
};
