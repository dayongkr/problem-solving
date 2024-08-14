class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        needs = {}
        cnt = 0

        for num in nums:
            need = k - num
            print(need)
            if need > 0:
                if need in needs:
                    cnt += 1
                    needs[need] -= 1
                    if needs[need] == 0:
                        del(needs[need])
                elif num in needs:
                    needs[num] += 1
                else:
                    needs[num] = 1

        return cnt