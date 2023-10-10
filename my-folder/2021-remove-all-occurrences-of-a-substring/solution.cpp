class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part) != s.npos) {
            int start = s.find(part);
            int l = s.length();
            string news = s.substr(0, start) + s.substr(start+part.length(), l-part.length()-start);
            s = news;
        }
        return s;
    }
};
