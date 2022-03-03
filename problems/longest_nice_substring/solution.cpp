class Solution {
public:
    string longestNiceSubstring(string s) {
    int maxLength = 0;        
    string result;
    for (int itr = 0; itr < s.size(); itr++)
    {
        bool large[26] = {};
        bool small[26] = {};
        for (int jtr = itr; jtr < s.size(); jtr++)
        {
            if (isupper(s[jtr]))
                large[s[jtr] - 'A'] = true;
            else
                small[s[jtr] - 'a'] = true;
            
            int length = jtr - itr + 1;
            if (length > maxLength)
            {
                int ktr = 0;
                for (; ktr < 26; ktr++){
                    if (large[ktr] != small[ktr]) break;
                }       
                
                if (ktr == 26)
                {
                    maxLength = length;
                    result = s.substr(itr, maxLength);                        
                }
            }
        }
    }
        
    if (maxLength == 0) return "";
    return result;        
    }
};