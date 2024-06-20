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
 * @return {TreeNode}
 */
var subtreeWithAllDeepest = function(root) {
    return dfs(root).node;
};

function dfs(root) {
    if(root == null) return {depth: -1, node: root};
    let left = dfs(root.left);
    let right = dfs(root.right);
    if(left.depth == right.depth) return {depth: left.depth+1, node: root};
    if(left.depth > right.depth) return {depth: left.depth+1, node: left.node};
    else return {depth: right.depth+1, node: right.node};
}