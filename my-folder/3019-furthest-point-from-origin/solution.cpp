class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int lefts = 0, rights = 0, optional = 0;
        
        for (char move : moves) {
            if (move == 'L') lefts++;
            else if (move == 'R') rights++;
            else if (move == '_') optional++;
        }
        
        if (lefts > rights) {
            return (lefts - rights) + optional;
        }
        else {
            return (rights - lefts) + optional;
        }    
    }
};
