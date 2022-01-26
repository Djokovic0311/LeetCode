class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int sum=0;
        int count=1;
        if(s.length()==0)
        return {0,0};    
        for(int i=0;i<s.length();i++)
        {
            sum+=widths[s[i]-'a'];
            if(sum>100)
            {
                sum=widths[s[i]-'a'];
                count++;
            }   
        }   
        vector<int> ans;
        ans.push_back(count);
        ans.push_back(sum);
        return ans;
    }
};