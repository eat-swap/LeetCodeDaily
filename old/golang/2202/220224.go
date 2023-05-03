package main

import "sort"

/**
 * Definition for singly-linked list.
 */

type ListNode struct {
	Val  int
	Next *ListNode
}

func sortList(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}

	arr := make([]*ListNode, 0)
	for ptr := head; ptr != nil; ptr = ptr.Next {
		arr = append(arr, ptr)
	}

	sort.Slice(arr, func(i, j int) bool {
		return arr[i].Val < arr[j].Val
	})

	n := len(arr)
	arr[n-1].Next = nil
	for i := 0; i < n-1; i++ {
		arr[i].Next = arr[1+i]
	}

	return arr[0]
}

func main() {

}
