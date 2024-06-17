class Solution {
    public int maxChunksToSorted(int[] arr) {
        if(arr == null || arr.length == 0) return 0;
        int n = arr.length;
        for(int i = 1; i < n; ++i)
            arr[i] = Math.max(arr[i-1], arr[i]);
        int count = 0;
        for(int i = 0; i < n; ++i)
            if(arr[i] == i) ++count;
        return count;
    }
}