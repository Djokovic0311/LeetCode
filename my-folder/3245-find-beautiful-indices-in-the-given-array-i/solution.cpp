class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        std::vector<int> beautifulIndices;
        int n = s.size(), lenA = a.size(), lenB = b.size();

        // Find all occurrences of string a and store their indices
        std::vector<int> indicesA;
        for (int i = 0; i <= n - lenA; ++i) {
            if (s.substr(i, lenA) == a) {
                indicesA.push_back(i);
            }
        }

        // Find all occurrences of string b and store their indices
        std::vector<int> indicesB;
        for (int i = 0; i <= n - lenB; ++i) {
            if (s.substr(i, lenB) == b) {
                indicesB.push_back(i);
            }
        }

        // Check each index of a to find if it's a beautiful index
        for (int indexA : indicesA) {
            for (int indexB : indicesB) {
                if (std::abs(indexA - indexB) <= k) {
                    beautifulIndices.push_back(indexA);
                    break; // No need to check further once a match is found
                }
            }
        }

        return beautifulIndices;    
    }
};
