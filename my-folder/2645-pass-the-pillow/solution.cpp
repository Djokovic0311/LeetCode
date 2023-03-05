class Solution {
public:
    int passThePillow(int n, int time) {
        int current = 1;
        bool forward = true;

        for (int i = 1; i <= time; i++) {
            if (forward) {
                current++;
                if (current == n) {
                    forward = false;
                }
            } else {
                current--;
                if (current == 1) {
                    forward = true;
                }
            }
        }
        return current;
    }
};
