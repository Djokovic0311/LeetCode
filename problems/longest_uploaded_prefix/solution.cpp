class LUPrefix {
public:
    int c = 0;
    vector<int> v;
    int n;
    
    LUPrefix(int w) {
        n = w;
        v = vector<int>(n);
    }
    
    void upload(int i) {
        v[i-1]=1;
        if(c+1==i){
            while(c<n && v[c]==1){
                c++;
            }
        }
    }
    
    int longest() {
        return c;    
    }
};
/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */