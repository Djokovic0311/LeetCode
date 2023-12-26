class Solution {
public:
    int calculate(string s) {
        stack<pair<int,int>> st; // pair(prev_calc_value , sign before next bracket () )
       
       long long int sum = 0;
       int sign = +1;
       
       for(int i = 0 ; i < s.size() ; ++i)
       {
           char ch = s[i];
           
            if(isdigit(ch)) {

                long long int num = 0;
                while(i < s.size() && isdigit(s[i])) {
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                i--;
                sum += sign * num;
                sign = +1;
            } else if(ch == '(') {
                st.push({sum, sign});
                sum = 0;
                sign = 1;
            } else if (ch == ')') {
                auto curr = st.top();
                st.pop();
                sum = curr.first + curr.second * sum;

            } else if (ch == '-') {
                sign = -1 * sign;
            }
       }
       return sum;
    }
};
