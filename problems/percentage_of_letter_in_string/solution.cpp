class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n = s.length();
        int cnt = 0;
        for(char c : s) {
            if(letter == c) cnt++;
        }
        int a = cnt * 100 / n;
        cout << double(cnt) * 100 / n;
        return a;
    }
};