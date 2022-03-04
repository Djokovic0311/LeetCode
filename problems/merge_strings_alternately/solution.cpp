class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int itr=0;
        string ans="";
        while(itr<word1.size()&&itr<word2.size()){
            ans+=word1[itr];
            ans+=word2[itr];
            itr++;
        }
        while(itr<word1.size()) ans+=word1[itr++];
        while(itr<word2.size())  ans+=word2[itr++];
        return ans;
    }
};