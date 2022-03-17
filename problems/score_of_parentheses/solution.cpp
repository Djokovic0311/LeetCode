class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.push(-1);
            }
            else {
                if(st.top() == -1) {
                    st.pop();
                    st.push(1);
                }
                else {
                    int res=st.top();
                    st.pop();
                    if(st.top()==-1){ //Case 2- (A)=2*A
                        st.pop();
                        st.push(2*res);
                    }
                    else{  
                        while(!st.empty()&&st.top()!=-1){
                            res+=st.top();
                            st.pop();
                        }
                        if(!st.empty()&&st.top()==-1){
                            st.pop();
                            res=res*2;
                        }
                        st.push(res);
                    }
                }
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};