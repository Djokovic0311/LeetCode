class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> freq1_even(26, 0), freq1_odd(26, 0);
        vector<int> freq2_even(26, 0), freq2_odd(26, 0);


        for (int i = 0; i < s1.size(); i++) {
            if (i % 2 == 0) { 
                freq1_even[s1[i] - 'a']++;
            } else { 
                freq1_odd[s1[i] - 'a']++;
            }
        }

        for (int i = 0; i < s2.size(); i++) {
            if (i % 2 == 0) { 
                freq2_even[s2[i] - 'a']++;
            } else { 
                freq2_odd[s2[i] - 'a']++;
            }
        }

        return freq1_even == freq2_even && freq1_odd == freq2_odd;        
    }
};
