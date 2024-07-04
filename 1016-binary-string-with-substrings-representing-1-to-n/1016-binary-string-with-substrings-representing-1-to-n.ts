function queryString(s: string, n: number): boolean {
    for (let i = n; i > n / 2; --i) {
        if (!s.includes(i.toString(2))) {
            return false;
        }
    }
    return true;
};