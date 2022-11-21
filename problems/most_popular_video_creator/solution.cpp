#define ll long long
class Solution {
private:
    // If the Total_Views of Creator is Same then it Sort according to lexicographically smallest String
    // else it sort according to Decreasing order of Total_Views
    static bool cmp(pair<ll,string> p1, pair<ll,string> p2){
        if(p1.first==p2.first)    return p1.second<p2.second;
        return p1.first>p2.first;
    }
public:
    vector<vector<string>> mostPopularCreator(vector<string>& c, vector<string>& id, vector<int>& v) {
        vector<vector<string>> ans;
        ll n = c.size(), maxi = INT_MIN;
        map<string, ll> m1;             // Creator, Total_Views
        map<string, vector<pair<ll,string>>> m2;    // Creator, ID
        
        // Store the values 
        for(int i=0; i<n; i++){
            m1[c[i]] += v[i];
            m2[c[i]].push_back(make_pair(v[i], id[i]));
            maxi = max(maxi, m1[c[i]]);            // Store the max_number_View
        }
        
        for(auto &[l, r]: m1){            
			// if Views == Max_Views
            if(r == maxi){
                sort(m2[l].begin(), m2[l].end(), cmp);  // Comparator Sort
                ans.push_back({l, m2[l].front().second});
            }
        }
        return ans;
    }
};