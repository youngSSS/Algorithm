package leetcode

func lengthOfLastWord(s string) int {
	cnt := 0
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] != ' ' {
			cnt += 1
		} else if cnt != 0 {
			return cnt
		}
	}
	return cnt
}
