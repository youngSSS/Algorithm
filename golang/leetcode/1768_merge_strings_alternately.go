package leetcode

func MergeAlternately(word1 string, word2 string) string {
	merged := ""
	idx1, idx2 := 0, 0
	l1, l2 := len(word1), len(word2)
	for {
		if idx1 < l1 {
			merged += word1[idx1 : idx1+1]
			idx1++
		}
		if idx2 < l2 {
			merged += word2[idx2 : idx2+1]
			idx2++
		}
		if idx1 == l1 && idx2 == l2 {
			return merged
		}
	}
}
