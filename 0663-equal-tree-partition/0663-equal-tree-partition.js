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
 * @return {boolean}
 */
var checkEqualTree = function(root) {
    var seen = [];
    var dfs = function(node) {
        if(!node) return 0;
        const subSum = node.val + dfs(node.left) + dfs(node.right);
        seen.push(subSum);
        return subSum;
    }
    const total = dfs(root);
    seen.pop();
    for(const s of seen) {
        if(2*s == total) return true;
    }
    return false;
};