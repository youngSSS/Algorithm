package leetcode

import (
	"sort"
	"strconv"
)

func CountCompleteSubarrays(nums []int) int {
	c := make([]int, len(nums))
	copy(c, nums)

	subs := getSubarrays(c)

	origin := toDistinctString(nums)
	cnt := 0
	for _, sub := range subs {
		sc := make([]int, len(sub))
		copy(sc, sub)
		str := toDistinctString(sub)
		if origin == str {
			cnt++
		}
	}
	return cnt
}

func getSubarrays(nums []int) [][]int {
	subs := make([][]int, 0)

	cnt := 1
	for cnt <= len(nums) {
		start := 0
		end := start + cnt

		for end <= len(nums) {
			s := make([]int, len(nums[start:end]))
			copy(s, nums[start:end])
			subs = append(subs, s)
			start += 1
			end += 1
		}
		cnt += 1
	}

	return subs
}

func toDistinctString(nums []int) string {
	m := make(map[int]struct{})
	sort.Slice(nums, func(i, j int) bool {
		return nums[i] < nums[j]
	})

	str := ""
	for _, n := range nums {
		if _, ok := m[n]; !ok {
			str += strconv.Itoa(n)
			m[n] = struct{}{}
		}
	}
	return str
}
