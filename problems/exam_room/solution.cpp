class ExamRoom {
    int n;
    set<int>seats;
public:
    ExamRoom(int N) {
        n=N;
    }
    
    int seat() {
        // cur is the current empty position initialised with zero and will be updated in this function
        // dist is the current maximum distance
        int dist=0;
        int cur=0;
        
        // is the seats is empty we can position the person on 0 seat
        if(!seats.empty()){
            auto it=seats.begin();
            
            // calculating initial 
            dist=*it;
            
            // doing this because we dont have any previous element to calculate the middle position
            if(dist==0){
                it++;
            }
            
            // calculating the middle position for every pair of positioned person
            while(it!=seats.end()){
                
                // calculating middle position
                int mid=(*it-*(prev(it)))/2;
                
                // if the mid is grater than current grater distance than we found our new answer
                // update dist and cur
                if(dist<mid){
                    dist=mid;
                    
                    // the new position will be mid steps away from prev(it)
                    cur=*prev(it)+dist;
                }
                
                // doing this till end
                it++;
            }
            
            // checking for the end position
            if(dist<((n-1)-*(seats.rbegin()))){
                cur=n-1;
            }
        }

        // finally insert the cur into set
        // return cur
        seats.insert(cur);
        return cur;
    }
    
    void leave(int p) {
        seats.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */