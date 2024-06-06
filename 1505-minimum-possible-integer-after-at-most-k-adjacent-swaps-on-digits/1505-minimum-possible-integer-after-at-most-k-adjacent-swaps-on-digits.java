class Solution {
  class Fenwick {
    private int[] sums;
    
    public Fenwick(int n) {
      this.sums = new int[n + 1];
    }
    
    public void update(int i, int delta) {
      ++i;
      while (i < sums.length) {
        this.sums[i] += delta;
        i += i & -i;
      }
    }
    
    public int query(int i) {
      int ans = 0;
      ++i;
      while (i > 0) {
        ans += this.sums[i];
        i -= i & -i;
      }
      return ans;
    }
  }
  
  public String minInteger(String num, int k) {
    int n = num.length();
    var used = new boolean[n];
    var pos = new ArrayList<ArrayDeque<Integer>>();
    for (int i = 0; i <= 9; ++i)
      pos.add(new ArrayDeque<Integer>());    
    for (int i = 0; i < num.length(); ++i)
      pos.get(num.charAt(i) - '0').offer(i);
    var tree = new Fenwick(n);
    var sb = new StringBuilder();
    while (k > 0 && sb.length() < n) {
      for (int d = 0; d <= 9; ++d) {
        Integer i = pos.get(d).peek();
        if (i == null) continue;
        int cost = i - tree.query(i - 1);
        if (cost > k) continue;        
        sb.append((char)(d + '0'));
        k -= cost;
        pos.get(d).removeFirst();
        tree.update(i, 1);
        used[i] = true;
        break;
      }
    }
    for (int i = 0; i < n; ++i)
      if (!used[i]) sb.append(num.charAt(i));
    return sb.toString();
  }
}