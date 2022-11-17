class Solution {
public:
    int minDeletions(string s) {
        vector<int> fr(26,0);
        int count=0;
        for(int i=0;i<s.size();i++)
            fr[s[i]-'a']++;
        sort(fr.begin(),fr.end());
        for(int i=0;i<25;i++)
        {
            if(fr[i]==fr[i+1] && fr[i]!=0)
            {
                count++;
                fr[i]--;
                i=0;
            }
        }
        return count;        
    }
};
