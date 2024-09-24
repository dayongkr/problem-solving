class Node {
    isEnd = false
    children = Array(10)
}

class Trie {
    constructor() {
        this.pool = [new Node()]
    }

    insert(string) {
        let cur = this.pool[0]

        for (let i = 0; i < string.length; i++) {
            const char = string[i]
            
            if (!cur.children[Number(char)]) {
                cur.children[Number(char)] = this.pool.length
                this.pool.push(new Node())
            } else if (i === string.length - 1) {
                return true
            }

            cur = this.pool[cur.children[Number(char)]]

            if (cur.isEnd){
                return true
            }
        }

        cur.isEnd = true

        return false
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