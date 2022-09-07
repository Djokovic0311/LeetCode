class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        for(int i = 0, m = words.size(); i < m; i++)
            for(int j = 0; j < words[i].size(); j++)
                if(j >= m || i >= words[j].size() || words[i][j] != words[j][i]) 
                    return false;
        
        return true;        
    }
};
