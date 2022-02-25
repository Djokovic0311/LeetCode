class Solution {
public:
    int compareVersion(string version1, string version2) {
        int ans = 0;
        int l1 = version1.size(), l2 = version2.size();
        for(int i = 0, j = 0; i<l1 || j<l2; i++, j++) {
            string s1 = "", s2 = "";
            while(i<l1 && version1[i] != '.') {
                if(s1.size() == 0 && version1[i] == '0') {
                    ++i; continue;
                }
                
                s1 += version1[i++];
            }
            
            while(j<l2 && version2[j] != '.') {
                if(s2.size() == 0 && version2[j] == '0') {
                    ++j; continue;
                }
                
                s2 += version2[j++];
            }
            if(s1.size() < s2.size()) return -1;
            else if(s2.size() < s1.size()) return 1;
            ans = s1.compare(s2);
            if(ans < 0) return -1;
            else if(ans > 0) return 1;
        }
        
        return 0;
    }
};