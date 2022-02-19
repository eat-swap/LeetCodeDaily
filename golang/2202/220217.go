package main

import "fmt"

func solver(candidates *[]int, target, prev int) [][]int {
	ret := make([][]int, 0)
	for _, v := range *candidates {
		if v >= prev && (target-v) >= v {
			t := solver(candidates, target-v, v)
			for i, _ := range t {
				t[i] = append([]int{v}, t[i]...)
			}
			ret = append(ret, t...)
		} else if target == v {
			ret = append(ret, []int{v})
		}
	}
	return ret
}

func combinationSum(candidates []int, target int) [][]int {
	return solver(&candidates, target, 0)
}

func main() {
	candidate := []int{2, 3, 5}
	ret := combinationSum(candidate, 8)
	for _, v := range ret {
		for _, vv := range v {
			fmt.Printf("%d ", vv)
		}
		fmt.Println()
	}
}
