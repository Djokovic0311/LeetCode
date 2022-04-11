class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;
        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[hand[i]]++;
        }
        while(!mp.empty()) {
            auto iter = mp.begin();
            int start = iter->first;
            cout << start << endl;
            for(int i = 1; i < groupSize; i++) {
                if(mp.find(start+i) == mp.end()) return false;
                else {
                    mp[start+i]--;
                    if(mp[start+i] == 0) mp.erase(start+i);
                }
            }
            mp[start]--;
            if(mp[start] == 0)
                mp.erase(start);
        }
        
        // cout << mp.begin()->first;
        return true;
    }
};
