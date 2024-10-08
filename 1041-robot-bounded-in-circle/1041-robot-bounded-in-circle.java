class Solution {
    public boolean isRobotBounded(String instructions) {
        int k = 0;
        int[] dist = new int[4];
        for(char c : instructions.toCharArray()) {
            if(c == 'L') k = (k+1)%4;
            else if(c == 'R') k = (k+3)%4;
            else dist[k]++;
        }
        return (dist[0] == dist[2] && dist[1] == dist[3]) || (k != 0);
    }
}