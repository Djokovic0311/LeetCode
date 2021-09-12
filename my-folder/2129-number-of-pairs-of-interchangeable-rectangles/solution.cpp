class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map <double, int> mp;
        int n = rectangles.size();
        long long res = 0; 
        for(auto rectangle : rectangles) {
            if(mp.find(double(rectangle[0]) / double(rectangle[1])) != mp.end()) {
                res += mp[double(rectangle[0]) / double(rectangle[1])];
                mp[double(rectangle[0]) / double(rectangle[1])]++;
            }
            else mp[double(rectangle[0]) / double(rectangle[1])] = 1;
        }

        // for(unordered_map<double, int>::iterator iter = mp.begin(); iter != mp.end(); iter++) {
        //         // cout << iter->first << " : " << iter->second << endl;
        //         res += iter->second
        //     }
        return res;
    }
};
