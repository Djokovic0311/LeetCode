class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.length();
        string res = "";
        int size = spaces.size();
        if(size == 1) {
            if(spaces[0] == 0) return " " + s;
            else return s.substr(0,spaces[0]) + " " + s.substr(spaces[0], n-spaces[0]);
        }
        for(int i = 0; i < size-1; i++) {
            if(spaces[i] == 0) res = " " + res;
            if(i == 0 && spaces[0] != 0) {res += s.substr(0,spaces[i]); res += " ";}
            
            res += s.substr(spaces[i],spaces[i+1] - spaces[i]);
            res += " ";                
            

        }
        res += s.substr(spaces[size-1], n-spaces[size-1]);
        return res;
    }
};
