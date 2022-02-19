package main

import (
	"fmt"

	"github.com/emirpasic/gods/trees/binaryheap"
	"github.com/emirpasic/gods/utils"
)

func minimumDeviation(nums []int) int {
	maxHeap := binaryheap.NewWith(func(a, b interface{}) int {
		return -utils.IntComparator(a, b)
	})
	min, ret := 0x7FFFFFFF, 0x7FFFFFFF
	for _, v := range nums {
		if v&1 == 1 {
			v <<= 1
		}
		maxHeap.Push(v)
		if min > v {
			min = v
		}
	}
	// fmt.Println(maxHeap.Values())
	for {
		xInterface, _ := maxHeap.Pop()
		x := xInterface.(int)
		if x&1 == 1 {
			if x-min < ret {
				return x - min
			}
			return ret
		}
		if ret > x-min {
			ret = x - min
		}
		if min > (x >> 1) {
			min = x >> 1
		}
		maxHeap.Push(x >> 1)
	}
}

func main() {
	fmt.Println(minimumDeviation([]int{4, 1, 5, 20, 3}))
}
