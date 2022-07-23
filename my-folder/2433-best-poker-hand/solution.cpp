class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        map<int,int> mp;
        for(auto r : ranks) mp[r]++;
        bool two = false, three = false;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            // cout << it->first << ' ' << it->second << endl;
            if(it->second >= 2) two = true;
            if(it->second >= 3) three = true;
        }
        if(suits[0] == suits[1] && suits[0] == suits[2] && suits[0] == suits[3] && suits[0] == suits[4])
            return "Flush";
        else if(three == true)
            return "Three of a Kind";
        else if(two == true)
            return "Pair";
        else return "High Card";
    }
};
