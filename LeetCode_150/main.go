package main

import "fmt"

func main() {

	fmt.Println(romanToInt("IV"))
	fmt.Println(romanToInt("III"))
	fmt.Println(romanToInt("LVIII"))
	fmt.Println(romanToInt("MCMXCIV"))
}

func romanToInt(s string) int {
	m := map[string]int{
		"I": 1,
		"V": 5,
		"X": 10,
		"L": 50,
		"C": 100,
		"D": 500,
		"M": 1000,
	}
	var sum = 0
	for index := 0; index < len(s); index++ {
		c := string(s[index])
		if c == "I" {
			if index+1 != len(s) && string(s[index+1]) == "V" {
				sum += 4
				index += 1
			} else if index+1 != len(s) && string(s[index+1]) == "X" {
				sum += 9
				index += 1
			} else {
				sum += 1
			}
		} else if c == "X" {
			if index+1 != len(s) && string(s[index+1]) == "L" {
				sum += 40
				index += 1
			} else if index+1 != len(s) && string(s[index+1]) == "C" {
				sum += 90
				index += 1
			} else {
				sum += 10
			}
		} else if c == "C" {
			if index+1 != len(s) && string(s[index+1]) == "D" {
				sum += 400
				index += 1
			} else if index+1 != len(s) && string(s[index+1]) == "M" {
				sum += 900
				index += 1
			} else {
				sum += 100
			}
		} else {
			sum += m[c]
		}
	}
	return sum
}
