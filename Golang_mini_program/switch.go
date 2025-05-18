package main

import "fmt"

func main() {
	number := "3"
	switch number {
	case "1":
		fmt.Println(1)
	case "2":
		fmt.Println(2)
	default:
		fmt.Println("default")
	}

}
