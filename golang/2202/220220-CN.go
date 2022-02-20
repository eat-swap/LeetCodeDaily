package main

import "fmt"

func isOneBitCharacter(bits []int) bool {
	var n = len(bits)
	if n == 1 || bits[n-2] == 0 {
		return true
	}
	// try applying codes from front to rear
	vis := make([]bool, n)
	vis[0] = true
	for i := 0; i < n-2; i++ {
		if !vis[i] {
			continue
		} else if bits[i] == 0 {
			vis[1+i] = true
		} else { // bits[i] == 1
			vis[2+i] = true
		}
	}
	return !vis[n-2]
}

func main() {
	fmt.Println(isOneBitCharacter([]int{1, 1, 1, 0}))
}
