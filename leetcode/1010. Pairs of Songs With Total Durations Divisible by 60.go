package leetcode

func numPairsDivisibleBy60(time []int) int {
	cnt := 0
	m := make(map[int]int)

	for _, t := range time {
		mod := t % 60
		need := (60 - mod) % 60
		cnt += m[need]
		m[mod] += 1
	}

	return cnt
}
