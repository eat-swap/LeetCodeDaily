package main

import "fmt"

/**
 * Definition for singly-linked list.
 */

type ListNode struct {
	Val  int
	Next *ListNode
}

func swapPairs(head *ListNode) *ListNode {
	ret := ListNode{0, head}
	ptr := &ret

	for ptr != nil {
		ptrN := ptr.Next
		if ptrN == nil {
			break
		}

		ptrNN := ptrN.Next
		if ptrNN == nil {
			break
		}

		ptrNNN := ptrNN.Next

		ptr, ptrNN.Next, ptr.Next, ptrN.Next = ptrN, ptrN, ptrNN, ptrNNN
	}

	return ret.Next
}

func main() {
	head := &ListNode{
		Val: 1,
		Next: &ListNode{
			Val: 2,
			Next: &ListNode{
				Val: 3,
				Next: &ListNode{
					Val: 4,
					Next: &ListNode{
						Val: 5,
						Next: &ListNode{
							Val:  6,
							Next: nil,
						},
					},
				},
			},
		},
	}

	head = swapPairs(head)

	for ptr := head; ptr != nil; ptr = ptr.Next {
		fmt.Println(ptr.Val)
	}
}
