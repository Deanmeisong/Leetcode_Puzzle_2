/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxAncestorDiff = function(root) {
    var ans = 0;
    
    var dfs = function(root, curMax, curMin) {
        if (root === null) return;
        ans = Math.max(ans, Math.max(Math.abs(root.val - curMax), Math.abs(root.val - curMin)));
        curMax = Math.max(curMax, root.val);
        curMin = Math.min(curMin, root.val);
        dfs(root.left, curMax, curMin);
        dfs(root.right, curMax, curMin);
    };

    if (root !== null) {
        dfs(root, root.val, root.val);
    }

    return ans;
};