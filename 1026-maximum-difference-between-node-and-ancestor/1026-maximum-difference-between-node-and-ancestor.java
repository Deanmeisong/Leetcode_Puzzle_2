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
    private int ans = 0;
    public int maxAncestorDiff(TreeNode root) {
        if(root == null) return 0;
        dfs(root, root.val, root.val);
        return ans;
    }
    private void dfs(TreeNode root, int curMax, int curMin) {
        if(root == null) return;
        ans = Math.max(ans, Math.max(Math.abs(root.val-curMax), Math.abs(root.val-curMin)));
        curMax = Math.max(curMax, root.val);
        curMin = Math.min(curMin, root.val);
        dfs(root.left, curMax, curMin);
        dfs(root.right, curMax, curMin);
    }
}