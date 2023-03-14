class Solution {
public:

    int numSplits(string s) {
        int n=s.size();
        vector<int> pre(n+1,0),suff(n+1,0);

        set<char>st;
        for(int i=0;i<s.size();++i){
            st.insert(s[i]);
            pre[i]=st.size();
        }
        st.clear();
        for(int i=n-1;i>=0;--i){
            st.insert(s[i]);
            suff[i]=st.size();
        }

        int ans=0;
        for(int i=1;i<n;++i){
            if(pre[i-1]==suff[i]){
                ans++;
            }
        }
        return ans;
    }
};
