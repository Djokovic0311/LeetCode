class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long res = 0;
        int n = skill.size();
        
        long long sum = 0;
        long long subsum = 0;
        unordered_map<int,int> mp;
        long long product = 0;
        
        for(int s : skill) sum += s, mp[s]++;
        
        if(sum % (n/2) != 0) return -1;
        else subsum = sum / (n/2);

        for(auto it = mp.begin(); it != mp.end(); it++) {
            // cout << it->first << endl;
            if(it->second != 0) {
                if(it->first * 2 != subsum) {
                    if(mp[subsum-it->first] != it->second) {
                        // cout << "here";
                        return -1;
                    }
                    else {
                        product += it->second * it->first * (subsum-it->first);
                        mp[subsum-it->first] = 0;
                        continue;
                    }
                }
                else {
                    // cout << it->first;
                    if(it->second % 2) {
                        // cout << it->first;
                        return -1;
                    }
                    else {
                        product += (long long int)(it->second / 2) * (long long int)it->first * (long long int)it->first;
                    }
                }                
            }
        }
        return product;
    }
};
