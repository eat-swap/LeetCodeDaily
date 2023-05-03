package main

import "fmt"

type Node struct {
	Pos  int
	Time int
	Next *Node
}

type Queue struct {
	front *Node
	rear  *Node
	count uint64
}

func (q *Queue) Initialise() {
	q.front = &Node{}
	q.rear = q.front
	q.count = 0
}

func (q *Queue) Push(node *Node) {
	q.rear.Next = node
	q.rear = node
	q.count++
}

func (q *Queue) Size() uint64 {
	return q.count
}

func (q *Queue) Empty() bool {
	return q.count == 0
}

func (q *Queue) Pop() {
	if q.count <= 0 {
		panic("trying to dequeue an empty queue")
	}
	q.front = q.front.Next
	q.count--
}

func (q *Queue) Top() Node {
	return *(q.front.Next)
}

func (q *Queue) TopAndPop() (ret Node) {
	ret = q.Top()
	q.Pop()
	return
}

type Queue2 struct {
	nodes []Node
}

func (q *Queue2) Initialise() {
	q.nodes = make([]Node, 0)
}

func (q *Queue2) Push(node *Node) {
	q.nodes = append(q.nodes, *node)
}

func (q *Queue2) Size() int {
	return len(q.nodes)
}

func (q *Queue2) Empty() bool {
	return len(q.nodes) == 0
}

func (q *Queue2) Pop() {
	if len(q.nodes) <= 0 {
		panic("trying to dequeue an empty queue")
	}
	q.nodes = q.nodes[1:]
}

func (q *Queue2) Top() Node {
	return q.nodes[0]
}

func (q *Queue2) TopAndPop() (ret Node) {
	ret = q.Top()
	q.Pop()
	return
}

/**
 * Warning: This solution did not pass all the test cases (TLE).
 * However, an exact re-implementation in C++ does,
 * the reason is still unknown.
 * The algorithm described should have a time complexity of O(n)
 * This golang version passed 41 / 43 test cases, which is
 * slightly better than the C# version (39 / 43).
 */

func pushDominoes(dominoes string) (ret string) {
	// Queue written by hand.
	// Interval: (front, rear]
	var q Queue
	q.Initialise()

	n := len(dominoes)
	result := make([]int, n)
	lastModified := make([]int, n)

	for i, v := range dominoes {
		if v != '.' {
			q.Push(&Node{
				Pos:  i,
				Time: 1,
			})
			lastModified[i] = 1
			if v == 'L' {
				result[i] = -1
			} else {
				result[i] = 1
			}
		}
	}

	for !q.Empty() {
		node := q.TopAndPop()

		if node.Pos > 0 && (lastModified[node.Pos-1] == node.Time+1 || lastModified[node.Pos-1] == 0) && result[node.Pos] < 0 {
			if lastModified[node.Pos-1] == 0 {
				q.Push(&Node{
					Pos:  node.Pos - 1,
					Time: node.Time + 1,
				})
				lastModified[node.Pos-1] = node.Time + 1
			}
			result[node.Pos-1]--
		} else if node.Pos < n-1 && (lastModified[node.Pos+1] == node.Time+1 || lastModified[node.Pos+1] == 0) && result[node.Pos] > 0 {
			if lastModified[node.Pos+1] == 0 {
				q.Push(&Node{
					Pos:  node.Pos + 1,
					Time: node.Time + 1,
				})
				lastModified[node.Pos+1] = node.Time + 1
			}
			result[node.Pos+1]++
		}
	}

	for _, v := range result {
		if v < 0 {
			ret += "L"
		} else if v > 0 {
			ret += "R"
		} else {
			ret += "."
		}
	}
	return
}

func main() {
	// fmt.Println(pushDominoes("RR.L"))
	fmt.Println(pushDominoes(".L.R...LR..L.."))
}
