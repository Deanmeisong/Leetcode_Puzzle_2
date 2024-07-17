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
    Stack<Integer> seen;
    public boolean checkEqualTree(TreeNode root) {
        seen = new Stack<>();
        int total = dfs(root);
        seen.pop();
        for(int s : seen)
            if(s * 2 == total) return true;
        return false;
    }
    
    private int dfs(TreeNode root) {
        if(root == null) return 0;
        seen.push(root.val + dfs(root.left) + dfs(root.right));
        return seen.peek();
    }
}