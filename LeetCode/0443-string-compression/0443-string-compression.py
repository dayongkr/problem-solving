class Solution:
    def compress(self, chars: List[str]) -> int:
        compresses = []
        cnt = 1
        prev= chars[0]
        
        for char in chars[1:]:
            if prev == char:
                cnt += 1
            else:
                compresses.append(prev)
                if cnt != 1:
                    compresses.append(str(cnt))
                prev = char
                cnt = 1

        
        compresses.append(prev)
        if cnt != 1:
            compresses.append(str(cnt))
                
        chars.clear()
        compresses = list("".join(compresses))
        for compress in compresses:
            chars.append(compress)

        return len(compresses)        