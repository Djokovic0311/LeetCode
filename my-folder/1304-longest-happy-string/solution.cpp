class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>>pq;
        if(a) pq.push({a,'a'});
        if(b) pq.push({b,'b'});
        if(c) pq.push({c,'c'});
        
        string res;
        while(!pq.empty()){
            auto [f, ch] = pq.top();
            pq.pop();
            if(res.size() < 2 || ch != res.back() || (res.size() >= 2 and ch == res.back() and ch != res[(int)res.size() - 2])){
                res.push_back(ch);
                if(--f > 0){
                    pq.push({f, ch});
                }
            }
            else{
                if(pq.empty()) break;
                auto [fDash, chDash] = pq.top();
                pq.pop();
                res.push_back(chDash);
                if(--fDash > 0){
                    pq.push({fDash, chDash});
                }
                pq.push({f, ch});
            }
        }
        return res;
    }
};
