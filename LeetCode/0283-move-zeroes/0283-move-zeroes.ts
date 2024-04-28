/**
 Do not return anything, modify nums in-place instead.
 */

function moveZeroes(nums: number[]): void {
    const N = nums.length
    if (N === 1) return
    let p1 = 0, p2 = 1
    while (p1 < N && p2 < N) {
        const cur1 = nums[p1], cur2 = nums[p2]
        if (cur1 === 0 && p1 > p2) p2 = p1 + 1
        else if (cur1 === 0 && cur2 !== 0) {
            nums[p1++] = cur2
            nums[p2++] = cur1
        }
        
        if (cur2 === 0) p2++
        if (cur1 !== 0) p1++
    }
};