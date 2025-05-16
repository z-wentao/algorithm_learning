package main

import (
	"fmt"
	"time"
)

func main() {
	start := time.Now()
	var sum = 0
	for i := 1; i < 1000; i++ {
		if i%3 == 0 || i%5 == 0 {
			sum += i
		}
	}
	t := time.Now()
	gap := t.Sub(start)
	fmt.Println(gap)
	fmt.Println(sum)
}
