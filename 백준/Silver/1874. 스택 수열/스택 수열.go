package main

import (
	"bufio"
	"bytes"
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
	result := bytes.Buffer{}
	m:=1
	var n, a int

	fmt.Fscan(reader, &n)

	for i:= 0; i < n; i++ {
		fmt.Fscan(reader, &a)
		pre.PushBack(a)
	}

	for e:= pre.Front(); e != nil; e = e.Next() {
		for m <= e.Value.(int) {
			stack.PushBack(m)
			m++
			result.WriteString("+\n")
		}
		if stack.Back().Value.(int) == e.Value.(int) {
			stack.Remove(stack.Back())
			result.WriteString("-\n")
		} else {
			break
		}
	}

	if stack.Len() == 0 {
		fmt.Fprintln(writer, result.String())
	} else {
		fmt.Fprintln(writer, "NO")
	}
}
