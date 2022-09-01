class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
    int n = currentState.size();

    vector<string> ans;
    
    for(int i = 0; i < n-1;i++)
    {
        if(currentState[i] == '+' && currentState[i+1] == '+')
        {
           string cs=currentState;
           cs[i] = '-';
           cs[i+1] = '-';
           ans.push_back(cs);
        }
    }
    return ans;
    }
};