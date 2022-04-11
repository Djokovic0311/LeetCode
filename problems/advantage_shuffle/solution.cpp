class Solution {
public:
    vector<int> advantageCount(vector<int>& a, vector<int>& b) {
        multiset<int> s;
        vector<int> v;
        for(int i=0;i<a.size();i++){
            s.insert(a[i]);
        }
        for(int i=0;i<b.size();i++){
            auto it = s.upper_bound(b[i]);
            if(it!=s.end()){
                v.push_back(*(it));
                s.erase(it);
            }
            else{
                v.push_back(*(s.begin()));
                s.erase(s.begin());
            }
        }
        return v;        
    }
};