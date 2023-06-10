package main

import (
	"bufio"
	"container/list"
	"fmt"
	"os"
)

func main()  {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	stack := list.New()
	pre := list.New()
	result := list.New()
	var n, a int
	fmt.Fscan(reader, &n)
	m:=1
	for i:= 0; i < n; i++ {
		fmt.Fscan(reader, &a)
		pre.PushBack(a)
	}
	for e:= pre.Front(); e != nil; e = e.Next() {
		for m <= e.Value.(int) {
			stack.PushBack(m)
			m++
			result.PushBack("+")
		}
		if stack.Back().Value.(int) == e.Value.(int) {
			stack.Remove(stack.Back())
			result.PushBack("-")
		} else {
			break
		}
	}
	if result.Len() == n * 2 {
		for e := result.Front(); e != nil; e = e.Next() {
			fmt.Fprintln(writer, e.Value)
		}
	} else {
		fmt.Fprintln(writer, "NO")
	}
}
