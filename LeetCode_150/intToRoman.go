package main

import "fmt"

var m = map[int]string{
	1:    "I",
	4:    "IV",
	5:    "V",
	9:    "IX",
	10:   "X",
	40:   "XL",
	50:   "L",
	90:   "XC",
	100:  "C",
	400:  "CD",
	500:  "D",
	900:  "CM",
	1000: "M",
}
var seq = []int{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}

func main() {
	fmt.Println(intToRoman(58))
	fmt.Println(intToRoman(3))
	fmt.Println(intToRoman(3749))
}

func intToRoman(num int) string {
	for i := 0; i < len(seq); i++ {
		if seq[i] <= num {
			return m[seq[i]] + intToRoman(num-seq[i])
		}
	}
	return ""
}
