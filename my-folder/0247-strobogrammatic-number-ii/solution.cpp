class Solution {
public:
    vector<vector<char>> reversiblePairs = {
        {'0', '0'}, {'1', '1'}, 
        {'6', '9'}, {'8', '8'}, {'9', '6'}
    };
    
    vector<string> findStrobogrammatic(int n) {
        queue<string> q;
        int currStringsLength;
        
        // When n is even, it means when decreasing by 2 we will go till 0.
        if (n % 2 == 0) {
            // We will start with 0-digit strobogrammatic numbers.
            currStringsLength = 0;
            q.push("");
        } else {
            // We will start with 1-digit strobogrammatic numbers.
            currStringsLength = 1;
            q.push("0");
            q.push("1");
            q.push("8");
        }
        
        while (currStringsLength < n) {
            currStringsLength += 2;
            for (int i = q.size(); i > 0; --i) {
                string number = q.front();
                q.pop();
                
                for (vector<char>& pair : reversiblePairs) {
                    if (currStringsLength != n || pair[0] != '0') {
                        q.push(pair[0] + number + pair[1]);
                    }
                }
            }
        }
        
        vector<string> stroboNums;
        while (!q.empty()) {
            stroboNums.push_back(q.front());
            q.pop();
        }
        
        return stroboNums;
    }
};
