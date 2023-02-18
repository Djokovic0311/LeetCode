class Solution {
public:
    vector<long long> st;
    vector<long long> lazy;
    
    void propagate(int v,int l ,int r){
        if(!lazy[v])return ;
        long long len = (r-l)+1;
        
        if(lazy[v]&1)
            st[v] = len-st[v];

        if(l!= r){
            lazy[v<<1] += lazy[v];
            lazy[v<<1|1]+= lazy[v];
        }
        
        lazy[v] = 0;
    }
    void update(int l,int r,int v,int sl,int sr ){
        propagate(v,sl,sr);
        if(r<sl || l>sr || sl>sr)return ;
        if(sl>= l && sr<=r){
            lazy[v] ++;
            propagate(v,sl,sr);
            return;
        }
        int m = (sl+sr)>>1;
        update(l,r,v<<1,sl,m);
        update(l,r,v<<1|1,m+1,sr);
        st[v] = st[v<<1]+st[v<<1|1];
    }

    long long query(int l,int r,int v,int sl,int sr){
        propagate(v,sl,sr);
        if(r<sl || l>sr || sl>sr)return 0; 
        if(sl>= l && sr<=r)return st[v];
        int m = (sl+sr)>>1;
        return query(l,r,v<<1,sl,m)+query(l,r,v<<1|1,m+1,sr);
    }
    
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        st.resize(4*n);
        lazy.resize(4*n);
        
        long long sum = 0;
        for(int i = 0;i<n;i++)
            sum+=nums2[i];
        
        vector<long long> ans;
        for(int i = 0;i<n;i++){
            if(nums1[i]== 1)
                update(i,i,1,0,n-1);
        }
        for(auto q:queries){
            if(q[0]==1)
                update(q[1],q[2],1,0,n-1);
            else if(q[0] == 2){
                long long c = query(0,n-1,1,0,n-1);
                sum+=c*(long long)q[1];
            }
            else
                ans.push_back(sum);
            
        }
        return ans;
        
    }
};