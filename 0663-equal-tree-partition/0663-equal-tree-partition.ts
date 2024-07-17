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

function checkEqualTree(root: TreeNode | null): boolean {
    var seen = [];
    var dfs = (node) => {
        if(!node) return 0;
        const subSum = node.val + dfs(node.left) + dfs(node.right);
        seen.push(subSum);
        return subSum;
    }
    const total = dfs(root);
    seen.pop();
    for(const s of seen)
        if(2*s == total) return true;
    return false;
};