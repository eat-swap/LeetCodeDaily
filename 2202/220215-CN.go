package main

import "fmt"

func luckyNumbers(matrix [][]int) []int {
	m, n := len(matrix), len(matrix[0])

	rowMin := make([]int, m)
	colMax := make([]int, n)

	for i := 0; i < m; i++ {
		rowMin[i] = 0x7FFFFFFF
		for j := 0; j < n; j++ {
			if matrix[i][j] < rowMin[i] {
				rowMin[i] = matrix[i][j]
			}
		}
	}

	for j := 0; j < n; j++ {
		colMax[j] = -0x7FFFFFFF
		for i := 0; i < m; i++ {
			if matrix[i][j] > colMax[j] {
				colMax[j] = matrix[i][j]
			}
		}
	}

	ret := make([]int, 0)
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j] {
				ret = append(ret, matrix[i][j])
			}
		}
	}

	return ret
}

func main() {
	args := [][]int{
		{3, 7, 8},
		{9, 11, 13},
		{15, 16, 17},
	}
	fmt.Println(luckyNumbers(args))
}
