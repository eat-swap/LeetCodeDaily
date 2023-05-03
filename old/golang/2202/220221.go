package main

func majorityElement(nums []int) int {
	var m = make(map[int]int)
	n := len(nums) >> 1
	for _, v := range nums {
		m[v]++
		if m[v] > n {
			return v
		}
	}
	// Never reaches
	return 0
}

func main() {
	// Tested in C++
}
