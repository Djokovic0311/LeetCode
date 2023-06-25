class Solution {
public:
static bool comp( pair<int,int>&a,pair<int,int>&b){
return a.first<b.first;
}
vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string d) {
vector<pair<int,int>>v;
int n = pos.size();

    for( int  i = 0; i< n; i++){
        v.push_back({pos[i], i});                //storing the position with index
    }
    sort(v.begin(),v.end(),comp);                //sort acc to pos
    stack<int>st;                               // store the index of remaining robot which having some health till end
    vector<int>ans;
    
    for( int i= 0; i < n; i++){
        
        int ind =  v[i].second;                 // finding respective index of that pos           
        
        if( d[ind] =='L'){                       // check the dir if it is left 
            if(st.empty()) ans.push_back(ind);   // if there is nothing to collide for  a particle that moving in left direction so it never collide to anyone  so its health never decrease  , so push into stack 
            else{
                while( !st.empty() && h[st.top()] <  h[ind]){      // check if anyone going to right dir, so checking which one is vanish
                    st.pop();
                    h[ind]--;
                }
                if( st.empty())ans.push_back(ind);
                else{
                    if( h[st.top() ] == h[ind])st.pop();
                    else {
                        h[st.top()]--;
                         if( h[st.top()]== 0)st.pop();
                         }
                }
            }
        }
        else {
            st.push(ind);
        }
    }
    
    while( !st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    sort( ans.begin(),ans.end());
    
    for( int i =0; i< ans.size(); i++)ans[i] = h[ans[i]];
    return ans;
}
};
