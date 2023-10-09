class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int l1 = str1.length(), l2 = str2.length();
        int i = 0, j = 0;
        while(i < l1 && j < l2) {
            if(str1[i] == str2[j]) {
                j++;
            }
            else {
                str1[i] = (((str1[i]-'a'+1)%26)+'a');
                if(str1[i] == str2[j]) {
                j++;
                }
            }
            i++;
        }

        return j == l2;
    }
};
