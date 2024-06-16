class Solution {
public:
    unordered_map<int,int> tree;
    int sum = 0;
    int pathSum(vector<int>& nums) {
        for(int x : nums) 
            tree[x/10] = x%10;
        traverse(nums[0]/10, 0);
        return sum;
    }
    void traverse(int key, int preSum) {
        int level = key/10;
        int pos = key%10;
        int left = (level+1)*10 + pos*2-1; int right = (level+1)*10+pos*2;
        int curSum = preSum + tree[key];
        if(!tree.count(left) && !tree.count(right)) {
            sum += curSum;
            return;
        }
        if(tree.count(left)) traverse(left, curSum);
        if(tree.count(right)) traverse(right, curSum);
    }
};