class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        // sort(grades.begin(),grades.end());
        // int res = 0;
        int n = grades.size();
        // int tmpsum = 0;
        // int tmpidx = 1;
        // while(tmpsum < n) {
        //     tmpsum += tmpidx;
        //     tmpidx++;
        //     cout << tmpidx <<  ' ' << tmpsum<<endl;
        //     // if(tmpsum < n) res++;
        // }
        int i;
        for(i = 1; i * (i+1)/2 < n; i++);
        return i*(i+1)/2 == n ? i : i-1;
    }
};