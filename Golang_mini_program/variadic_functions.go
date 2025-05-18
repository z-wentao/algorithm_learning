package main

import (
	"fmt"
	"slices"
)

func sum(strs ...string) string {
	s := ""
	for _, sub := range strs {
		s += sub
	}
	return s
}

func main() {
	ss := []string{"1", "2", "3", "4"}
	ss = slices.Insert(ss, 1, "6")
	fmt.Println(sum(ss...))
}
