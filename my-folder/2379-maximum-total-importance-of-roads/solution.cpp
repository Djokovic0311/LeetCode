class Solution {
public:
    static bool cmp(vector<long long>& a, vector<long long>& b) {
    
            return a[1] < b[1];
    }
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long res = 0;
        vector<int> v(n,0);
        for(auto r : roads) {
            v[r[0]]++;
            v[r[1]]++;
        }
        vector<vector<long long>> record;
        for(int i = 0; i < n; i++) {
            record.push_back({i,v[i]});
        }
        sort(record.begin(),record.end(),cmp);
        for(int i = 0; i < n; i++) {
            res += (i+1) * record[i][1];
        }
        return res;
    }
};
