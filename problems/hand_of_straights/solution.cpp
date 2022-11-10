class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mp;
        int n = hand.size();
        if(n % groupSize != 0) return false;
        for(int h : hand)
            mp[h]++;
        while(!mp.empty()) {
            auto it = mp.begin();
            int start = it->first;
            for(int i = 1; i < groupSize; i++) {
                if(mp.find(start+i) == mp.end())
                    return false;
                mp[start+i]--;
                if(mp[start+i] == 0) mp.erase(start+i);
            }
            mp[start]--;
            if(mp[start] == 0)
                mp.erase(start);
        }
        return true;
    }
};