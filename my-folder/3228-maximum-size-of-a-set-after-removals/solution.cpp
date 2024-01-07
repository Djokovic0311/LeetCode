class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        set<int> st1(nums1.begin(), nums1.end());
        set<int> st2(nums2.begin(), nums2.end());
        set<int> st;
        int n = nums1.size();
        if(st1.size() <= n/2 && st2.size() <= n/2) {
            for(int e : st1) {
                st.insert(e);
            }
            for(int e : st2) {
                st.insert(e);
            }
            return st.size();
        } else if(st1.size() > n/2 && st2.size() <= n/2) {
            for (int element : st2) {
                st1.erase(element);
            }
            if(st1.size() > n/2) {
                return st2.size() + n/2;
            } else return st2.size() + st1.size();
        } else if(st2.size() > n/2 && st1.size() <= n/2) {
            for (int element : st1) {
                st2.erase(element);
            }
            if(st2.size() > n/2) {
                return st1.size() + n/2;
            } else return st2.size() + st1.size();
        } else {
            set<int> intersection;
            set_intersection(st1.begin(), st1.end(), 
                          st2.begin(), st2.end(), 
                          inserter(intersection, intersection.begin()));
            for(int e: intersection) {
                st1.erase(e);
                st2.erase(e);
            }
            int sz = intersection.size();
            cout << sz;
            if(st1.size() <= n/2 && st2.size() <= n/2) {
                
                return st1.size() + st2.size() + min(static_cast<int>(n - st1.size() - st2.size()), sz);
            } else if(st1.size() > n/2 && st2.size() > n/2){
                return n;
            } else {
                int small = min(st1.size(), st2.size());
                return n/2 + small + min(n/2-small, sz);
            }
        }
        
        
    }
};
