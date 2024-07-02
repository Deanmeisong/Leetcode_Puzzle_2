func numMovesStones(a int, b int, c int) []int {
    x := min(a, min(b, c))
    z := max(a, max(b, c))
    y := a+b+c-x-z
    mi, ma := 0, 0
    if z-x > 2 {
		mi = 2
		if y-x < 3 || z-y < 3 {
			mi = 1
		}
        ma = z-x-2
    }
    return []int{mi, ma}
}