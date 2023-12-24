class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        long long maximumArea = 0, modulo = 1e9 + 7;
        unordered_set<long long> differences;
        hFences.push_back(1); 
        hFences.push_back(m); 
        vFences.push_back(1); 
        vFences.push_back(n); 

        for(int h1 = 0; h1 < hFences.size(); ++h1){
            for(int h2 = 0; h2 < hFences.size(); ++h2){
                if(h1 != h2 ) differences.insert(abs(hFences[h1] - hFences[h2]));
            }
        }

        for(int v1 = 0; v1 < vFences.size(); ++v1){
            for(int v2 = 0; v2 < vFences.size(); ++v2){
                if(v1 != v2  && differences.find(abs(vFences[v1] - vFences[v2])) != differences.end()) {
                    maximumArea = max(maximumArea, (long long)abs(vFences[v1] - vFences[v2]));
                }
            }
        }

        return (maximumArea == 0) ? -1 : ((maximumArea * maximumArea) % modulo);       
            
    }
};
