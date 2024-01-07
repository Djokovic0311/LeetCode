class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        int moves = 0;
        
        // Check if the rook can capture the queen directly
        if (a == e || b == f) {
            // Rook can capture the queen in one move if they are on the same row or column.
            if(((c-a)*(c-e) < 0 && b == d && b == f ) || ((d-b) * (d-f) < 0 && a == c && c == e)) {
                moves = 2;
            }
            else moves = 1;
        } else {
            // Otherwise, it will take the rook two moves - one to get to the correct row or column, 
            // and another to capture the queen.
            moves = 2;
        }
        
        

        // Check if the bishop can capture the queen
        if (abs(c - e) == abs(d - f) && (!((a-c)*(a-e) < 0 && (b-d)*(b-f) < 0 && abs(a-c) == abs(b-d)))) {
            // Bishop can capture the queen in one move if they are on the same diagonal.
            // This is checked by seeing if the distance between the rows is the same as the distance between the columns.
            moves = min(moves, 1);
        }


        return moves;
    }
};
