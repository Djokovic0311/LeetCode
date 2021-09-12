class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.length();
        int i = 0;
        while(word[i] != ch && i < n) i++;
        cout << i;
        if(i == n) return word;
        else {
            string head = word.substr(0,i+1);
            reverse(head.begin(),head.end());
            string tail = word.substr(i+1, n-i-1);
            return head + tail;
        }
        
    }
};
