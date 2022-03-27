class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& q, int l) {
        int k=(l+1)/2,start=pow(10,k-1),end=pow(10,k)-1;
        vector<long long> A;
        for(int i=0;i<q.size();i++)
        {
            int a=start+q[i]-1;     //Since the palindromes are in order 'a' is the half palindeome of the required palindrome 
            if(a>end)               //We want the number of length 'k', if it crosses the length 'k' then our output will be '-1'
            {
                A.push_back(-1);
                continue;
            }
            string s=to_string(a),t=s;
            reverse(t.begin(),t.end());
            if(l%2==0)
            {
                s+=t;               //Number is "321" then palindrome of even length will be "321" "123"
                A.push_back(stoll(s));
            }
            else
            {
                s+=t.substr(1);     //Number is "321" then palindrome of odd length will be "321" "_23"
                A.push_back(stoll(s));
            }
        }
        return A;   
    }
};