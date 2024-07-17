/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public bool CheckEqualTree(TreeNode root) {
        List<int> seen = new List<int>();
        int dfs(TreeNode node) {
            if(node == null) return 0;
            int subSum = node.val + dfs(node.left) + dfs(node.right);
            seen.Add(subSum);
            return subSum;
        }
        int total = dfs(root);
        seen.RemoveAt(seen.Count-1);
        foreach(int s in seen)
            if(2 * s == total) return true;
        return false;
    }
}