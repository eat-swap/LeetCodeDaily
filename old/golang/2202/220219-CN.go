package main

import "fmt"

// Interval [L, R]
func reverse(arr *[]int, L, R int) {
	for L < R {
		(*arr)[L], (*arr)[R] = (*arr)[R], (*arr)[L]
		L++
		R--
	}
}

func pancakeSort(arr []int) (ret []int) {
	n := len(arr)
	for i := n; i > 0; i-- {
		maxVal, maxPos := -1, -1
		for j := 0; j < i; j++ {
			if arr[j] > maxVal {
				maxVal, maxPos = arr[j], j
			}
		}
		ret = append(ret, maxPos+1, i)
		reverse(&arr, 0, maxPos)
		reverse(&arr, 0, i-1)
	}
	return
}

func main() {
	fmt.Println(pancakeSort([]int{3, 2, 4, 1}))
}
