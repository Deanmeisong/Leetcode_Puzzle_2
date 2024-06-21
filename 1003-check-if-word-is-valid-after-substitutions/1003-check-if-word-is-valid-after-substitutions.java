class Solution {
    public boolean isValid(String s) {
        List<Character> list = new ArrayList<>();
        for(char c : s.toCharArray()) {
            list.add(c);
            int n = list.size();
            if(n >= 3 && list.get(n-3) == 'a' && list.get(n-2) == 'b' && list.get(n-1) == 'c') {
                list.remove(n-1);
                list.remove(n-2);
                list.remove(n-3);
            }
        }
        return list.size() == 0;
    }
}