class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> str;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words.size();j++){
               if(i!=j){
                   // size_t found=;
                   if(words[j].find(words[i]) != -1){
                       str.push_back(words[i]);
                       break;
                   }
               }
            }
        }
        return str;
    }
};
