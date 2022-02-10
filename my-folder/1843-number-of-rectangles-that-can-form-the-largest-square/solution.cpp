class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        vector<int> tmp;
        int n = rectangles.size();
        int mx = 0;
        int times = 0;
        for(int i = 0; i < n; i++) {
            int tmp = min(rectangles[i][0],rectangles[i][1]);
            cout << tmp<<endl;
            if(mx < tmp) {
                mx = tmp;
                times = 1;
            }
            else if(mx == tmp) {
                cout << 'a' <<endl;
                times++;
            }
        }
        return times;
    }
};
