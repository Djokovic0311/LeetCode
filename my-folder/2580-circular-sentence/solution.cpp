class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.length();
        int i = 0;
        while(sentence[i] == ' ') i++;
        if(i != 0) return false;
        i = n-1;
        while(sentence[i] == ' ') i--;
        if(i != n-1) return false;
        for(int j = 0; j < n; j++) {
            if(sentence[j] == ' ') {
                if(sentence[j-1] != sentence[j+1]) return false;
            }
        }
        return sentence[0] == sentence[n-1];
        // int j = 0;
        // vector<string> 
        // while(i < n) {
        //     j = i;
        //     while(sentence[j] != ' ') j++;
        //     string word = 
        // }
    }
};
