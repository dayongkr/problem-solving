class Node():
    def __init__(self):
        self.isEnd = False
        self.children = {}

class Trie():
    def __init__(self):
        self.root = Node()
    
    def insert(self, string):
        root = self.root
        
        for char in string:
            if char not in root.children:
                root.children[char] = Node()
            
            root = root.children[char]
            
            if root.isEnd:
                return True
            
        root.isEnd = True
        
        return bool(root.children)
    

def solution(phone_book):
    trie = Trie()
    for item in phone_book:
        if trie.insert(item):
            return False
        
    return True