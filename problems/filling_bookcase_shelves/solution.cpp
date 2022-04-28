class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        books.insert(books.begin(),{0,0});
        vector<int> dp(books.size(),INT_MAX); // dp[i] represents the minimum total height of shelf for first ith books
        dp[0] = 0;
        int width, height, j;
        for(int i=1;i<books.size();i++){
            width = books[i][0];
            height = books[i][1];
            j = i-1;
            while (0<= j && width<=shelfWidth){
                dp[i] = min(dp[i], dp[j]+height);
                width += books[j][0];
                height = max(height, books[j][1]);
                j--;
            }
        }
        return dp.back();
    }
};