class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c); 
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    string sortVowels(string s) {
        priority_queue<char, vector<char>, greater<char>> pq;
        for(char c : s)
            if(isVowel(c))
                pq.push(c);

        for(int i = 0; i < s.length(); i++) {
            if(isVowel(s[i])) {
                s[i] = pq.top();
                pq.pop();
            }
        }
        return s;        
    }
};
