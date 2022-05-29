struct Node
{
    int elementID;
    int stepsToeliminate;
};
 
class Solution {
public:
    
    int totalSteps(vector<int>& a) {
        int n = a.size();
        int ret = 0;
		// Which round will the position i be removed, set a big value to represent never be removed.
        vector<int>f(n, n+n);
        stack<int>st;
        st.push(0);
        for(int i = 1;i<n;i++){
            int ans = 1;
            while((!st.empty())&&a[st.top()]<=a[i]){
                ans=max(ans, f[st.top()]+1);
                st.pop();
            }
            if(ans<n+n){
                ret=max(ret, ans);
            }
            f[i] = ans;
            st.push(i);
        }
        return ret;
    }
};