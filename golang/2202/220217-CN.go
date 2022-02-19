package main

import "fmt"

func isValid(n, x, y int) bool {
	return x >= 0 && y >= 0 && x < n && y < n
}

func knightProbability(n, k, row, column int) float64 {
	var dX = [8]int{-2, -1, 1, 2, 2, 1, -1, -2}
	var dY = [8]int{1, 2, 2, 1, -1, -2, -2, -1}
	// dp[k -> remaining step][x][y]
	var dp, dpNext [25][25]float64
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			dp[i][j] = 1.0
		}
	}
	for i := 0; i < k; i++ {
		for x := 0; x < n; x++ {
			for y := 0; y < n; y++ {
				dpNext[x][y] = 0.0
				for idx := 0; idx < 8; idx++ {
					if isValid(n, x+dX[idx], y+dY[idx]) {
						dpNext[x][y] += dp[x+dX[idx]][y+dY[idx]]
					}
				}
				dpNext[x][y] /= 8.0
			}
		}
		dp = dpNext
	}

	return dp[row][column]
}

func main() {
	fmt.Println(knightProbability(1, 0, 0, 0))
}
