package main

import (
	"fmt"
	"time"
)

func main() {
	start := time.Now()
	a := (333 * (3 + 999) / 2)
	b := (((995 / 5) * (5 + 995)) / 2)
	c := (((990 / 15) * (990 + 15)) / 2)
	t := time.Now()
	elapsed := t.Sub(start)
	fmt.Println(elapsed)
	fmt.Println(a + b - c)
}
