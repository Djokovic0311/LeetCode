class Solution {
public:
    bool judgeCircle(string moves) {
        int c = 0, r =0;
        for(char ch: moves) {
            switch(ch){
            case 'U': r--;break;
            case 'D': r++;break;
            case 'L': c--;break;
            case 'R': c++;break;                 
            }

        }
        cout << r;
        return r == 0 && c == 0;
    }
};