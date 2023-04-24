/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        List<TreeNode> list = new ArrayList<>();
        list.add(root);
        
        if(root == null) return result;
        int a=0;
        while(list.size() != 0){
            System.out.println(a);
            a+=1;
            System.out.println(a);
            List<TreeNode> nextlist = new ArrayList<>();
            List<Integer> temp = new ArrayList<>();
            for(TreeNode i:list){
                if(i != null) {
                if(i.left!=null){
                    nextlist.add(i.left);
                }
                if(i.right!=null){

                    nextlist.add(i.right);
                }
                temp.add(i.val);
                }

            }
            result.add(temp);
            list=nextlist;
            System.out.println(list);
            

        }
        return result;
    }
}
