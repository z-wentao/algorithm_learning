package main

import "fmt"

var valuemap = map[int]string{
	1000: "M",
	900:  "CM",
	500:  "D",
	400:  "CD",
	100:  "C",
	90:   "XC",
	50:   "L",
	40:   "XL",
	10:   "X",
	9:    "IX",
	5:    "V",
	4:    "IV",
	1:    "I",
}

var seq = []int{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}

func f(d int) string {
	for _, val := range seq {
		if d >= val {
			return valuemap[val] + f(d-val)
		}
	}
	return ""
}

func main() {
	Integer := []int{33, 3749}
	Roman := []string{"XXXIII", "MMMDCCXLIX"}
	for i := range Integer {
		if f(Integer[i]) != Roman[i] {
			fmt.Println("no")
			break
		}
	}
	fmt.Println("yes")
}

// Reflection:
// 1. Understand the problem:
// 	draw map
// 2. Devise the plan:
// 	Divide Large question to smaller one when thinking the problem
// 	Jot down the pseudo code
// 3. Implement the plan:
// 	Go's map is unorded so I need create an array to track the sub sequence
// 	Write test in our implementation
// 	Revise the implementation to make sure there is no typo or syntax error
// 4. Reflect and refactor
