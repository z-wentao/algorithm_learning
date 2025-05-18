package main

import "fmt"

func main() {
	if number := 1; number < 0 {
		fmt.Println("negative")
	} else {
		fmt.Println(">0")
	}
	// fmt.Println(number)
	// can only use in check branch
}
