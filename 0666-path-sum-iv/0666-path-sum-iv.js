/**
 * @param {number[]} nums
 * @return {number}
 */
var pathSum = function(nums) {
    let sum = 0;
    let tree = new Map();
    for(let x of nums) tree.set(Math.floor(x/10), x%10);

    function dfs(root, pre) {
        let cur = pre + tree.get(root);
        let lev = Math.floor(root/10); let pos = root%10;
        let left = (lev+1)*10 + 2*pos-1; let right = (lev+1)*10 + 2*pos;
        if(!tree.has(left) && !tree.has(right)) {
            sum += cur;
            return;
        }
        if(tree.has(left)) dfs(left, cur);
        if(tree.has(right)) dfs(right, cur);
    }

    dfs(Math.floor(nums[0]/10), 0);
    
    
    return sum;
};