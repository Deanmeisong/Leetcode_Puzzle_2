class Solution {
    public int monotoneIncreasingDigits(int n) {
        String s = Integer.toString(n);
        char[] chars = s.toCharArray();
        int change = 0;
        for(int i = chars.length-1; i >= 1; --i) {
            if(chars[i] < chars[i-1]) {
                chars[i-1]--;
                change = i;
            }
        }
        
        if(change == 0) return n;
        for(int i = change; i < chars.length; ++i)
            chars[i] = '9';
        return Integer.parseInt(new String(chars));
    }
}