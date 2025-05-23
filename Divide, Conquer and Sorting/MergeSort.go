package main

import (
	"fmt"
)

func Merge(left, right []int) []int {
	var results []int
	i, j := 0, 0
	for i < len(left) && j < len(right) {
		if left[i] <= right[j] {
			results = append(results, left[i])
			i++
		} else {
			results = append(results, right[j])
			j++
		}
	}
	results = append(results, left[i:]...)
	results = append(results, right[j:]...)
	return results
}

func MergeSort(nums []int) []int {
	if len(nums) <= 1 {
		return nums
	} else {
		mid := len(nums) / 2
		return Merge(MergeSort(nums[:mid]), MergeSort(nums[mid:]))
	}
}

func main() {
	nums := []int{5, 1, 1, 2, 0, 0}
	sorted := MergeSort(nums)
	fmt.Println(sorted)
}
