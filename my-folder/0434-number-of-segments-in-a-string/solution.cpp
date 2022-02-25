class Solution {
public:
    int countSegments(string s) {
        int cnt=0;
        stringstream ss(s);
        string word;
        while(ss>>word)
        {
            cnt++;
        }
        return cnt;        
    }
};
