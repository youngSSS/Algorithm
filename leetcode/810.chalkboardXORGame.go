package leetcode

func xorGame(nums []int) bool {
	res := nums[0]
	for i := 1; i < len(nums); i++ {
		res = res ^ nums[i]
	}
	return res == 0 || len(nums)%2 == 0
}

