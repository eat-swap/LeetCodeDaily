package main

import "fmt"

func singleNumber(nums []int) int {
	var x = 0
	for _, v := range nums {
		x ^= v
	}
	return x
}

func main() {
	var args = []int{4, 1, 2, 1, 2}
	fmt.Println(singleNumber(args))
}
