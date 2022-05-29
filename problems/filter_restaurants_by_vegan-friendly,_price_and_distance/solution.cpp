class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        if(a[1]==b[1])return a[0]>b[0];
        return a[1]>b[1];
    }
    vector<int> filterRestaurants(vector<vector<int>>& res,int veg, int p, int d) {
        vector<vector<int>> v;
        for(auto k:res){
            if((k[2]==veg || veg==0) && k[3]<=p && k[4]<=d)v.push_back(k);
        }       
        sort(v.begin(),v.end(),cmp);
        vector<int> ans;
        for(auto k:v)ans.push_back(k[0]);
        return ans;
    }
};