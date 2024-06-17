function maxChunksToSorted(arr: number[]): number {
    if(arr == null || arr.length == 0) return 0;
    for(let i = 1; i < arr.length; ++i)
        arr[i] = Math.max(arr[i], arr[i-1])
    let count = 0;
    for(let i = 0; i < arr.length; ++i)
        if(arr[i] === i) ++count;
    return count;
};