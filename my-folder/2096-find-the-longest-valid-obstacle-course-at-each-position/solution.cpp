class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
         vector<int>  v(obstacles.size()+1, INT_MAX), ans;

        for(auto it : obstacles)   {
            int ind = upper_bound(v.begin(), v.end(), it) - v.begin();
            v[ind] = it;
            ans.push_back(ind+1);
        }

        return ans;        
    }
};
