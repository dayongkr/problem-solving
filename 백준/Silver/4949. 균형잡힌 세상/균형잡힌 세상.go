package main

import (
	"bufio"
	"container/list"
	"fmt"
	"os"
	"strings"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	s := ""
	stack := list.New()

	for {
		stack.Init()
		s, _ = r.ReadString('\n')
		s = strings.TrimSuffix(s, "\n")
		if s == "." {
			break
		}
		for _, v := range s {
			if v == '(' || v == '[' {
				stack.PushBack(v)
			} else if v == ')' {
				if stack.Len() == 0 {
					stack.PushBack(v)
					break
				} else if stack.Back().Value == '(' {
					stack.Remove(stack.Back())
				} else {
					stack.PushBack(v)
					break
				}
			} else if v == ']' {
				if stack.Len() == 0 {
					stack.PushBack(v)
					break
				} else if stack.Back().Value == '[' {
					stack.Remove(stack.Back())
				} else {
					stack.PushBack(v)
					break
				}
			}
		}
		if stack.Len() == 0 {
			fmt.Fprintln(w, "yes")
		} else {
			fmt.Fprintln(w, "no")
		}
	}
}
