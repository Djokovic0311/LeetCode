class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
    int n = player1.size();
    vector<int> score1(n, 0), score2(n, 0);

    for (int i = 0; i < n; i++) {
        if (i > 0 && player1[i - 1] == 10) {
            score1[i] = 2 * player1[i];
        } else if (i > 1 && player1[i - 2] == 10) {
            score1[i] = 2 * player1[i];
        } else {
            score1[i] = player1[i];
        }

        if (i > 0 && player2[i - 1] == 10) {
            score2[i] = 2 * player2[i];
        } else if (i > 1 && player2[i - 2] == 10) {
            score2[i] = 2 * player2[i];
        } else {
            score2[i] = player2[i];
        }
    }

    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        sum1 += score1[i];
        sum2 += score2[i];
    }

    if (sum1 > sum2) {
        return 1;
    } else if (sum1 < sum2) {
        return 2;
    } else {
        return 0;
    }        
    }
};
