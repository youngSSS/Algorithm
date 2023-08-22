package leetcode

var left, right, max int
var pivots []int

func splitArray(nums []int, k int) int {
	max = 1000000000

	pivots = make([]int, k+1)
	for i := 0; i < k; i++ {
		pivots[i] = i
	}
	pivots[k] = len(nums)

	for i := k - 1; i >= 0; i-- {
		left = 0
		right = 0
		split(nums[pivots[i]:pivots[i+1]], i)
	}

	return max
}

func split(nums []int, pIdx int) {
	mid := len(nums) / 2

	localLeft := 0
	for i := 0; i < mid-1; i++ {
		localLeft += nums[i]
	}
	localLeft += left

	localRight := 0
	for i := mid; i < len(nums); i++ {
		localRight += nums[i]
	}
	localRight += right

	localMax := 0
	if localLeft > localRight {
		localMax = localLeft
		right += localRight
	} else {
		localMax = localRight
		left += localLeft
	}

	if max > localMax {
		max = localMax
		pivots[pIdx] += mid
	}

	if localLeft > localRight {
		split(nums[0:mid], pIdx)
	} else if localLeft < localRight {
		split(nums[mid:], pIdx)
	}

	return
}
