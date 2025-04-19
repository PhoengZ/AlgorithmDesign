package main

import (
	"fmt"
	"sort"
)

var target, target1, k int

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func f(v []int, sel []bool, total int, now int, count int, ans *int) {
	if count == target {
		*ans = min(*ans, abs(total-k))
		return
	}
	if total >= k && *ans <= abs(total-k) {
		return
	}
	if target1-now+count < target {
		return
	}
	sel[now] = true
	f(v, sel, total+v[now], now+1, count+1, ans)
	sel[now] = false
	f(v, sel, total, now+1, count, ans)
}

func main() {
	var n, m int
	fmt.Scanf("%d %d %d", &n, &m, &k)
	target = m
	target1 = n
	v := make([]int, n)
	sel := make([]bool, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &v[i])
	}
	sort.Slice(v, func(i, j int) bool {
		return v[i] > v[j]
	})
	ans := 1000000000
	f(v, sel, 0, 0, 0, &ans)
	fmt.Println(ans)
}
