class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int j=0, res=0;
        for(int i=0; i<g.size(); i++){
            if(j==s.size())
                break;
            while(j<s.size()){
                if(s[j++]>=g[i]){
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};
