/**
 * Definition for a rope tree node.
 * class RopeTreeNode {
 *     int len;
 *     String val;
 *     RopeTreeNode left;
 *     RopeTreeNode right;
 *     RopeTreeNode() {}
 *     RopeTreeNode(String val) {
 *         this.len = 0;
 *         this.val = val;
 *     }
 *     RopeTreeNode(int len) {
 *         this.len = len;
 *         this.val = "";
 *     }
 *     RopeTreeNode(int len, TreeNode left, TreeNode right) {
 *         this.len = len;
 *         this.val = "";
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public char getKthCharacter(RopeTreeNode root, int k) {
        if(root == null) return '\0';
        if(root.len == 0) {
            if(root.val.length() >= k)
                return root.val.charAt(k-1);
            return '\0';
        }

        if(root.left != null) {
            RopeTreeNode leftNode = root.left;
            if(leftNode.val.length() >= k ||leftNode.len >= k) {
                return getKthCharacter(leftNode, k);
    
            }
            int leftCount = leftNode.len + leftNode.val.length();
            return getKthCharacter(root.right, k-leftCount);
        } else return getKthCharacter(root.right, k);
    }

}
