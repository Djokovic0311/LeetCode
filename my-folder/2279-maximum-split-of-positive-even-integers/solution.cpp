class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        int i;
        vector<long long> res1;
        if(finalSum % 2 != 0) return res1;
        int count = 0;
        long long k = finalSum/2;
        for (i = 1; ; i++) {
            if (k < i) {count = i - 1; break;}
            else {k -= i; }
        }
        k = finalSum/2;
        cout << count;
        vector<long long> res(count);
        for(int i = 0; i < count; i++) {
            if(i < count-1) {res[i] = (i+1) * 2; k -= (i+1);}
            else {res[i] = k * 2;}
            
        }
        return res;
        
    }
};
