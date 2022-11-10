/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int up_sum=0,maxweight=1,sum=0;
    void dfs(vector<NestedInteger>& nestedList,int depth){
        int n=nestedList.size();
        if(n!=0){maxweight=max(maxweight,depth);}
        for(int i=0;i<n;i++){
            if(nestedList[i].isInteger()){
                up_sum+=nestedList[i].getInteger()*depth;
                sum+=nestedList[i].getInteger();
            }
            else{
                dfs(nestedList[i].getList(),depth+1);
            }   
        }
    }
    
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        dfs(nestedList,1);
        int ans=sum*maxweight-up_sum+sum;
        return ans;  
    }
};
