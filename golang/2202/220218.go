package main

import (
	"fmt"
)

func removeKdigits(num string, k int) (ret string) {
	stack := make([]int32, 0)
	for _, v := range num {
		for k > 0 && len(stack) > 0 && stack[len(stack)-1] > v {
			stack = stack[:len(stack)-1]
			k--
		}
		stack = append(stack, v)
	}
	if k > 0 {
		stack = stack[:len(stack)-k]
	}
	for _, v := range stack {
		ret += string(v)
	}
	for len(ret) > 1 && ret[0] == '0' {
		ret = ret[1:]
	}
	if len(ret) == 0 {
		return "0"
	}
	return
}

func main() {
	fmt.Println(removeKdigits("1432219", 3))
}
