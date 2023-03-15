class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        if(target==1)
            return 0;
        if(target%2==0&&maxDoubles>0)
        {
            maxDoubles--;
            return 1+minMoves(target/2,maxDoubles);
        }
        if(maxDoubles==0)
            return target-1;
        return 1+minMoves(target-1,maxDoubles);
    }
};
