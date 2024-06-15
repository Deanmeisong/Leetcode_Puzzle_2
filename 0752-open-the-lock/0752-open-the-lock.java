class Solution {
    public int openLock(String[] deadends, String target) {
        Set<String> deadSet = new HashSet<>(Arrays.asList(deadends));
        if(deadSet.contains("0000")) return -1;
        Queue<String> q = new LinkedList<>(Collections.singletonList("0000"));
        for(int steps = 0; !q.isEmpty(); steps++) {
            for(int size = q.size(); size > 0; --size) {
                String curr = q.poll();
                if(curr.equals(target)) return steps;
                for(String nei : neighbors(curr)) {
                    if(deadSet.contains(nei)) continue;
                    deadSet.add(nei);
                    q.offer(nei);
                }
            }
        }
        return -1;
    }
    
    List<String> neighbors(String code) {
        List<String> results = new ArrayList<>();
        for(int i = 0; i < 4; ++i)
            for(int diff = -1; diff <= 1; diff += 2) {
                results.add(code.substring(0,i) + (code.charAt(i) - '0' + diff + 10)%10 + "" + code.substring(i+1));
            }
        return results;
    }
}