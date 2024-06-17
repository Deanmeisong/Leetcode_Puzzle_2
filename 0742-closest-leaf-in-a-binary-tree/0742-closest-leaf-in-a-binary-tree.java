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
    public Map<TreeNode, List<TreeNode>> graph = new HashMap<>();
    public TreeNode start;
    public int findClosestLeaf(TreeNode root, int k) {
        dfs(root, null, k);
        Set<TreeNode> seen = new HashSet<>();
        Queue<TreeNode> q = new LinkedList();
        q.add(start);
        seen.add(start);
        while(!q.isEmpty()) {
            TreeNode node = q.poll();
            if(node != null) {
                if(node.left == null && node.right == null) return node.val;
                for(TreeNode nei : graph.get(node)) {
                    if(!seen.contains(nei)) {
                        seen.add(nei);
                        q.add(nei);
                    }
                }
            }
        }
        return 0;
    }
    
    public void dfs(TreeNode node, TreeNode parent, int val) {
        if(node != null) {
            if(node.val == val) start = node;
            if(!graph.containsKey(node)) graph.put(node, new LinkedList<TreeNode>());
            if(!graph.containsKey(parent)) graph.put(parent, new LinkedList<TreeNode>());
            graph.get(node).add(parent);
            graph.get(parent).add(node);
            dfs(node.left, node, val);
            dfs(node.right, node, val);
        }
        
    }
}