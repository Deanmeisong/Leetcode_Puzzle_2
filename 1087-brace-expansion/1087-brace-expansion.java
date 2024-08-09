class Solution {
    public String[] expand(String s) {
        List<String> list = new ArrayList<>();
        int n = s.length();
        for(int i = 0; i < n; ++i) {
            if(s.charAt(i) == '{') {
                StringBuilder sb = new StringBuilder();
                int j = i+1;
                while(j < n && s.charAt(j) != '}') {
                    if(s.charAt(j) == ',') {
                        ++j;
                        continue;
                    }
                    sb.append(s.charAt(j));
                    ++j;
                }
                list.add(sb.toString());
                i = j;
            } else {
                list.add(s.charAt(i)+"");
            }
        }
        
        List<String> res = new ArrayList<>();
        dfs(list, res, new StringBuilder(), 0);
        int size = res.size();
        String[] ans = new String[size];
        for(int i = 0; i < size; ++i)
            ans[i] = res.get(i);
        Arrays.sort(ans);
        return ans;
    }
    
    private void dfs(List<String> list, List<String> res, StringBuilder sb, int pos) {
        if(sb.length() == list.size()) {
            res.add(sb.toString());
            return;
        }
        
        for(char c : list.get(pos).toCharArray()) {
            sb.append(c);
            dfs(list, res, sb, pos+1);
            sb.setLength(sb.length()-1);
        }
  
    }
} 