public class Solution {
    public IList<int> PowerfulIntegers(int x, int y, int bound) {
        HashSet<int> hs = new HashSet<int>();
        for (int i = 1; i < bound; i *= x)
        {
            for (int j = 1; i + j <= bound; j *= y)
            {
                hs.Add(i + j);
                if (y == 1) break;
            }
            if (x == 1) break;
        }
        return new List<int>(hs);
    }
}