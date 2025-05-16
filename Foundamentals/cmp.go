package main

import (
	"fmt"
	"time"
)

var o = []int{-5, -3, 1, 4, 7}

// func binary_search(r int, l int, s int) int {
// 	if r == l {
// 		return -1
// 	}
// 	mid := (r + l) >> 1
// 	if o[mid] == s {
// 		return mid
// 	} else if o[mid] > s {
// 		return binary_search(r, mid, s)
// 	} else {
// 		return binary_search(mid+1, l, s)
// 	}
// }

func linear_search(number int) int {
	for i, nu := range o {
		if nu == number {
			return i
		}
	}
	return -1
}

func main() {
	start := time.Now()
	index := linear_search(4)
	t := time.Now()
	gap := t.Sub(start)
	fmt.Println(gap)
	fmt.Println(index)
}
