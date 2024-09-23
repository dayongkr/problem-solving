class Node {
    isEnd = false
    children = new Map()
}

class Trie {
    constructor() {
        this.root = new Node()
    }

    insert(string) {
        let cur = this.root
        
        for (const char of string) {
            if (!cur.children.has(char)) {
                cur.children.set(char, new Node())
            }
            
            cur = cur.children.get(char)
            
            if (cur.isEnd){
                return true
            }
        }
        
        cur.isEnd = true
        
        return Boolean(cur.children.size)
    }
    
    
}

function solution(phone_book) {
    const trie = new Trie()
    
    for (const item of phone_book) {
        if (trie.insert(item)) {
            return false
        }
    }
    
    return true
}