class Solution {
public:

    static bool cmp(const pair<string,int> &p1,const pair<string,int> &p2)//要用常数，不然编译错误 
    {
        return p1.second>p2.second;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        
       vector<pair<string,int> > arr;
        vector<string> res;
        int n = names.size();
       for (int i = 0; i < n; i++)
       {
            
            arr.push_back(make_pair(names[i],heights[i]));
       }
       sort(arr.begin(),arr.end(),cmp);
       for(int i = 0; i < n; i++) {
           res.push_back(arr[i].first);
       }
        return res;
    }
};