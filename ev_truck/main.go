package main

import "fmt"

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	var n, m int
	fmt.Scanf("%d %d", &n, &m)
	g := make([][]int, n)
	for i := 0; i < n; i++ {
		g[i] = make([]int, n)
		for j := 0; j < n; j++ {
			g[i][j] = 1000000000
		}
	}
	for i := 0; i < n; i++ {
		g[i][i] = 0
	}
	for i := 0; i < m; i++ {
		var a, b, c int
		fmt.Scanf("%d %d %d", &a, &b, &c)
		g[a][b] = c
		g[b][a] = c
	}
	for k := 0; k < n; k++ {
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				g[i][j] = min(g[i][j], g[i][k]+g[k][j])
			}
		}
	}
	sol := 0
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if g[i][j] != 1000000000 {
				sol = max(sol, g[i][j])
			}
		}
	}
	fmt.Println(sol)
}
