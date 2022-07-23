#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
class Solution {
public:
    vector<int> countSmaller(vector<int>& n) {
        const int N = n.size();
        vector<int> v(N,0);
        ordered_set s;
        v[N-1]=0;
        s.insert(n[N-1]);
        for(int i=N-2;i>=0;i--){
            int it = s.order_of_key(n[i]);
            v[i]=it;
            s.insert(n[i]);
        }
        return v;
    }
    
};
