class Solution {
public:
    int addMinimum(string word) {
        int countA = 0, countB = 0, countC = 0;
        int insertions = 0;
        int l = word.length();

        for (int i = 0;i < l;i++) {
            char ch = word[i];
            if (ch == 'a') {
                countA++;
            } else if (ch == 'b') {
                if (countA > 0 && i>0 && word[i-1] =='a') {
                    countA--;
                } else {
                    insertions++; // Insert 'a'
                    
                }
                countB++;
            } else { // ch == 'c'
                if (countB > 0 && i>0 && word[i-1] =='b') {
                    countB--;
                } else {
                    insertions++; // Insert 'b'
                    if (countA > 0 && i>0 && word[i-1] =='a') {
                        countA--;
                    } else {
                        insertions++; // Insert 'a'
                    }
                }
            }
        }

        // cout << countA << " " << countB<<endl;
        // cout << insertions << endl;

        // For remaining 'a's and 'b's, we need to insert 'b's and 'c's, and 'c's respectively
        insertions += 2 * countA + countB;

        return insertions;
    }
};
