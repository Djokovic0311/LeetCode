class Solution {
public:
    string nextClosestTime(string time) {
        set<char> sorted;
        for(auto c:time){
            if(c==':') continue;
            sorted.insert(c);
        }
       
        string res = time;
        for(int i = time.size() -1; i>=0; i--){
            if(time[i] == ':' ) continue;
            auto it = sorted.find(time[i]);
             if(*it != *sorted.rbegin()){// not the largest number
                it++; // go to the next element
                res[i] = *it;
                if((i>=3 && stoi(res.substr(3,2))<60) ||(i<2&&stoi(res.substr(0,2))<24))       
                    return res;      
             } 
             res[i]=*sorted.begin(); // take the smallest number
        }
        return res;          
    }
};
