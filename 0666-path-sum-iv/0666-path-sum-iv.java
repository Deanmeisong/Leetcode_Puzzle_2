class Solution {
    int sum = 0;
    Map<Integer,Integer> tree = new HashMap<>();
    public int pathSum(int[] nums) {
        if (nums == null || nums.length == 0) return 0;

        for (int num : nums) {
            int key = num / 10;
            int value = num % 10;
            tree.put(key, value);
        }
        dfs(nums[0]/10, 0);
        return sum;
    }
    
    private void dfs(int root, int pre) {
        int cur = pre + tree.get(root);
        int lev = root/10, pos = root%10;
        int left = ++lev*10+pos*2-1, right = lev*10+pos*2;
        if(!tree.containsKey(left) && !tree.containsKey(right)) {
            sum += cur;
            return;
        }
        if(tree.containsKey(left)) dfs(left, cur);
        if(tree.containsKey(right)) dfs(right, cur);
    }
}