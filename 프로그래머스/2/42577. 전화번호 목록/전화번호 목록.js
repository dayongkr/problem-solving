1
2
3
4
5
6
7
8
function solution(phoneBook) {
    return !phoneBook.sort().some((t,i)=> {
        if(i === phoneBook.length -1) return false;

        return phoneBook[i+1].startsWith(phoneBook[i]);        
    })
}
