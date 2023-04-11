package leetcode

func searchInsert(nums []int, target int) int {
	return search(nums, target, 0)
}

func search(nums []int, target, base int) int {
	if len(nums) == 1 {
		if nums[0] < target {
			return base + 1
		}
		if nums[0] > target {
			return base
		}
	}

	mid := len(nums) / 2

	if nums[mid] == target {
		return base + mid
	}

	if nums[mid] > target {
		if mid == 0 {
			return base
		}
		return search(nums[:mid], target, base)
	}

	if nums[mid] < target {
		if mid+1 >= len(nums) {
			return base + mid + 1
		}
		return search(nums[mid+1:], target, base+mid+1)
	}

	return 0
}
