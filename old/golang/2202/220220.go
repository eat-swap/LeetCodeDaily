package main

import "sort"

func removeCoveredIntervals(xs [][]int) int {
	sort.Slice(xs, func(i, j int) bool {
		return (xs[i][1] - xs[i][0]) < (xs[j][1] - xs[j][0])
	})

	vis := make([]bool, len(xs))
	var ret = len(xs)
	for i, v := range xs {
		for j := 0; j < i; j++ {
			if !vis[j] && xs[j][0] >= v[0] && xs[j][1] <= v[1] {
				vis[j] = true
				ret--
			}
		}
	}
	return ret
}

func main() {
	// Tested in C++ version
}
