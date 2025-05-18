package main

import "fmt"

func climbStairs(n int) int {
	a, b := 1, 1
	for _ = range n {
		a, b = b, a+b
	}
	return a
}

func main() {
	fmt.Println(climbStairs(1))
	fmt.Println(climbStairs(2))
	fmt.Println(climbStairs(3))
	fmt.Println(climbStairs(4))
}
