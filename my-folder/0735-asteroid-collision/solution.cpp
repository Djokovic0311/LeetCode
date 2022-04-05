class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int> s; 
        for (int i = 0; i < a.size(); i++) {
            if (a[i] > 0 || s.empty() || s.back() < 0) 
                s.push_back(a[i]);
            else if (s.back() <= -a[i]) { 
                if(s.back() < -a[i]) i--; 
                s.pop_back(); 
            }
        }
        return s;        
    }
};
