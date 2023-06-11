package main

import (
	"bufio"
	"container/list"
	"fmt"
	"os"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	k := 0
	stack := list.New()
	fmt.Fscan(r, &k)

	for i := 0; i < k; i++ {
		var n int
		fmt.Fscan(r, &n)
		if n == 0 {
			stack.Remove(stack.Back())
		} else {
			stack.PushBack(n)
		}
	}
	k=0
	for stack.Len() != 0 {
		k += stack.Remove(stack.Back()).(int)
	}
	fmt.Fprint(w, k)
}
