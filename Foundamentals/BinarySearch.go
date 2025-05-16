package main

import (
	"fmt"
	"time"
)

var o = []int{-5, -3, 1, 4, 7}

func binary_search(r int, l int, s int) int {
	if r == l {
		return -1
	}
	mid := (r + l) >> 1
	if o[mid] == s {
		return mid
	} else if o[mid] > s {
		return binary_search(r, mid, s)
	} else {
		return binary_search(mid+1, l, s)
	}
}

func main() {
	start := time.Now()
	a := binary_search(0, len(o), -3)
	t := time.Now()
	gap := t.Sub(start)
	fmt.Println(gap)
	if a == 1 {
		fmt.Println("ok")
	}
	if binary_search(0, len(o), -4) == -1 {
		fmt.Println("ok")
	}
	if binary_search(0, len(o), -5) == 0 {
		fmt.Println("ok")
	}
	if binary_search(0, len(o), 9) == -1 {
		fmt.Println("ok")
	}
}
