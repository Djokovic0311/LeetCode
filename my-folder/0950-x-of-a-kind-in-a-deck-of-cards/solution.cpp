class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        std::unordered_map<int, int> map;
        for (int i=0; i<deck.size(); i++) 
            map[deck[i]]++;
        
        int x = INT_MAX;
        for (std::pair<int, int> num : map) 
        {
            if (num.second < x)
                x = num.second;
        }
        if (x < 2) return false;
        
        for(int i=2; i<=x;i++) 
        {
            bool good = true;
            for (std::pair<int, int> num : map) 
            {
                if (num.second % i != 0)
                {
                    good = false;
                    break;
                }
                    
            }
            if (good) return true;
        }
            
        return false;        
    }
};
