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
    int ans = 0;
    public int longestUnivaluePath(TreeNode root) {
        if(root == null) return 0;
        dfs(root, root.val);
        return ans;
    }
    private int dfs(TreeNode node, int val) {
        if(node == null) return 0;
        int lv = dfs(node.left, node.val);
        int rv = dfs(node.right, node.val);
        ans = Math.max(lv+rv, ans);
        if(node.val == val) return Math.max(lv, rv) + 1;
        return 0;
    }
}