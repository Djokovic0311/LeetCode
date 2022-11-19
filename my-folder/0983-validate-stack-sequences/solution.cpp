class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int j = 0;

        int n = pushed.size();

        for(int i = 0; i < n; i++) {
            stk.push(pushed[i]);
            while(stk.size() > 0 && stk.top() == popped[j]){ // if st.peek() values equal to popped[j];
                stk.pop(); // then pop out
                j++; // increment j
            }
        }
        return stk.empty();
    }
};
