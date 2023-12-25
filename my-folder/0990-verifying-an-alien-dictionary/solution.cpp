class Solution {
public:
    unordered_map<char, int> mp;
    bool isAlienSorted(vector<string>& words, string order) {        
        for(int i = 0; i < size(order); i++) mp[order[i]] = i;  
        for(int i = 0; i < size(words) - 1; i++)
            if(!checkOrder(words[i], words[i + 1])) return false;
        return true;        
    }    
    bool checkOrder(string& a, string& b){
        int i = 0;
        int n1 = a.length(), n2 = b.length();
        while(i < n1 && i < n2) {
            if(mp[a[i]] != mp[b[i]])
                return mp[a[i]] < mp[b[i]];
            i++;
        }
        return n1 <= n2;
    }

};
