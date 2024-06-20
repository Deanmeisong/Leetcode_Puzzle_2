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
    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        return dfs(root).node;
    }
    
    private class Res {
        int depth; TreeNode node;
        Res(int depth, TreeNode node) {
            this.depth = depth;
            this.node = node;
        }
    }
    
    private Res dfs(TreeNode root) {
        if(root == null) return new Res(-1, null);
        Res l = dfs(root.left);
        Res r = dfs(root.right);
        int dl = l.depth; int dr = r.depth;
        TreeNode node = dl == dr ? root : (dl > dr) ? l.node : r.node;
        return new Res(Math.max(dl, dr)+1, node);
    }
}