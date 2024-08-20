from collections import deque

class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        radiantQ, direQ = deque(), deque()
        length = len(senate)

        for i in range(len(senate)):
            if senate[i] == "R":
                radiantQ.append(i)
            else:
                direQ.append(i)
        
        while radiantQ and direQ:
            radiant, dire = radiantQ.popleft(), direQ.popleft()

            if radiant < dire:
                radiantQ.append(length)
            else:
                direQ.append(length)
            
            length += 1
        
        return "Radiant" if radiantQ else "Dire"
