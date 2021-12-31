#include <iostream>
#include <cmath>

class Solution {
public:
	static bool checkPerfectNumber(int num) {
		switch (num) {
			case 6:
			case 28:
			case 496:
			case 8128:
			case 33550336:
				return true;
			default:
				return false;
		}
	}
};

int main() {
	for (int i = 1; i < 100000000; ++i) {
		int s = 1;
		int lim = int(std::sqrt(i + 0.50));
		for (int j = 2; j <= lim; ++j)
			if (i % j == 0)
				s += j + i / j;
		if (s == i)
			std::printf("%d\n", i);
	}
	return 0;
}

/**
 * Use this golang program to do multi-threaded searching:
 *
package main

import (
	"fmt"
	"math"
	"sync"
	"time"
)

type taskArgument struct {
	L uint32
	R uint32
}

var (
	tasks        = make(chan taskArgument)
	printContent = make(chan string)
)

const (
	step  = 500000
	limit = 100000000
)

func taskExecutor(mutex *sync.Mutex) {
	mutex.Lock()
	defer mutex.Unlock()
	for {
		args, ok := <-tasks
		if !ok {
			return
		}
		for i := args.L; i <= args.R; i++ {
			var s uint32 = 1
			lim := uint32(math.Sqrt(float64(i) + 0.5))
			for j := uint32(2); j <= lim; j++ {
				if i%j == 0 {
					s += j + i/j
				}
			}
			if s == i {
				printContent <- fmt.Sprintf("%d", i)
			}
		}
		printContent <- fmt.Sprintf("Finishing searching [%d, %d]", args.L, args.R)
	}
}

func main() {
	go Printer()
	threads := 20
	locks := make([]sync.Mutex, threads)
	start := time.Now()
	for i := 0; i < threads; i++ {
		go taskExecutor(&locks[i])
	}
	for i := 1; i < limit; i += step {
		tasks <- taskArgument{
			L: uint32(i),
			R: uint32(i + step - 1),
		}
	}
	close(tasks)
	time.Sleep(1 * time.Second)
	for i := 0; i < threads; i++ {
		locks[i].Lock()
	}
	end := time.Now()
	fmt.Println(end.Sub(start))
}

func Printer() {
	for {
		s, ok := <-printContent
		if !ok {
			return
		}
		fmt.Println(s)
	}
}
 */