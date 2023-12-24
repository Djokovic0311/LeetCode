class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        n--;

        while(n) {
            string tmp = "";
            int l = res.length();
            int i = 0, j = 0;
            while(i < l && j < l) {
                while(j < l && res[i] == res[j])
                    j++;
                tmp += to_string(j-i) + res[i];
                i = j;
            }
            res=tmp;
            n--;
        }

        return res;
    }
};
