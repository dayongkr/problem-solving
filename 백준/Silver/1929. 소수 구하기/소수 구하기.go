package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	var n, m int
	var arr [10000001]int = [10000001]int{}
	fmt.Fscan(r, &n, &m)
	for i := n; i <= m; i++ {
		if arr[i] == 2 && i != 1 {
			fmt.Fprintln(w, i)
			continue
		} else if arr[i] == 1 {
			continue
		}
		for j := 2; j*j <= i; j++ {
			if i%j == 0 {
				arr[i] = 1
				for k := i * 2; k <= m; k += i {
					arr[k] = 1
				}
				break
			}
		}
		if arr[i] == 0 && i != 1 {
			arr[i] = 2
			fmt.Fprintln(w, i)
		}
	}
}
