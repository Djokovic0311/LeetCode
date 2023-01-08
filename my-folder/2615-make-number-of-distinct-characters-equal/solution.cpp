class Solution {
public:
    bool isItPossible(string word1, string word2) {
        map<char, int> mp1, mp2;
        for(char c : word1) mp1[c]++;
        for(char c : word2) mp2[c]++;
        int m = mp1.size(), n = mp2.size();
        if(word1==word2) return true;
        for(auto it1 = mp1.begin(); it1 != mp1.end(); it1++) {
            for(auto it2 = mp2.begin(); it2 != mp2.end(); it2++) {
                if(it1->first == it2->first) continue;
                int tmpm = m, tmpn = n;
                if(it1->second == 1) tmpm--;
                if(mp1.find(it2->first) == mp1.end()) tmpm++;
                if(it2->second == 1) tmpn--;
                if(mp2.find(it1->first) == mp2.end()) tmpn++;
//                 cout << it1->first << ' ' << it2->first << endl;
//                 cout << tmpm << " " << tmpn << endl;
                
                if(tmpm == tmpn) return true;
            }
        }
        cout << endl;
        return false;
    }
};
