class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<int> alphabets(26, 0);
        for(int i=0; i<letters.size() ;i++){
            alphabets[letters[i] - 'a']++;
        }
        int index = (target - 'a' + 1)%26;
        while(alphabets[index] == 0){
            index = (index+1)%26;
        }
        return 'a'+index;        
    }
};