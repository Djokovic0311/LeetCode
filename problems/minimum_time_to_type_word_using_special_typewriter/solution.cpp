class Solution {
public:
    int minTimeToType(string word) {
        // int op = 0;
        int op = word.length();
        char start = 'a';
        // op += min(abs('a' - word[0]), 26-abs(a - word[0]));
        // op += n;
        for(char c : word) {
            op += min(abs(start - c), 26-abs(start -c));
            // op++;
            cout << op << endl;
            start = c;
        }
        return op;
    }
};