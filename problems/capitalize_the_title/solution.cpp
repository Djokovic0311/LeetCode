class Solution {
public:
    string capitalizeTitle(string title) {
        string res = "";
        stringstream ss(title);
        string word;
        while(ss >> word) {
            // convert a word into lowercase
            transform(word.begin(), word.end(), word.begin(), ::tolower);            
            
            // if word size is more than 2, then convert first letter to uppercase
            if(word.size() > 2) word[0] = toupper(word[0]);
            res += word + " ";   
        }
        res.pop_back();
        return res;
    }
};