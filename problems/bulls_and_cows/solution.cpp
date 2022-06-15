class Solution {
public:
    string getHint(string secret, string guess) {
        int mp1[10] = {0};
        int mp2[10] = {0};
        int bull=0,cow=0;
        for(int i=0;i<secret.length();i++) {
            if(secret[i]==guess[i]) {
                bull++;
            } else {
                mp1[secret[i]-'0']++;
                mp2[guess[i]-'0']++;
            }
        }
        
        for(int i=0;i<10;i++) {
            if(mp1[i]!=0 && mp2[i]!=0) {
                cow += min(mp1[i], mp2[i]);
                
            }
        }
        
        return to_string(bull) + "A" + to_string(cow) + "B";        
    }
};