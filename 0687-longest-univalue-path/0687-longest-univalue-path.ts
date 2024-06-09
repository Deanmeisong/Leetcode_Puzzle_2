/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function longestUnivaluePath(root: TreeNode | null): number {
    var ans = 0;
    if(root == null) return 0;
    var dfs = function(node, val) {
        if(node == null) return 0;
        var lv = dfs(node.left, node.val);
        var rv = dfs(node.right, node.val);
        ans = Math.max(lv+rv, ans);
        if(node.val == val) return Math.max(lv, rv) + 1;
        return 0;
    }
    dfs(root, root.val)
    return ans
};