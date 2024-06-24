function shipWithinDays(weights: number[], days: number): number {
    let l = Math.max(...weights);
    let r = weights.reduce((a,b) => a+b, 0);
    while(l < r) {
        let m = Math.floor((r-l)/2 + l);
        let cur = 0, need = 1;
        for(const w of weights) {
            if(cur + w > m){
                ++need;
                cur = 0;
            }
            cur += w;
        }
        if(need > days) l = m + 1;
        else r = m;
    }
    return l;
};