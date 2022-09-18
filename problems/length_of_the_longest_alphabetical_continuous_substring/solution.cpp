class Solution {
public:
    int longestContinuousSubstring(string s) {
        char prevChar;
        string currentString = "";
        string longestString = "";
        if(s.length()==1) return 1;
        for (char c : s) {
            if (prevChar == c-1){
                currentString += c;
                if (currentString.length() > longestString.length())
                    longestString = currentString;               
            }

            else{
                currentString = c;
            }
                
            prevChar = c;            
        }

        return longestString.length() == 0?1 : longestString.length(); 
    }
};