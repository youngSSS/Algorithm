package leetcode

import (
	"math"
	"strconv"
)

func SingleNumber(nums []int) int {
	posBinSum := make([]int, 32)
	negBinSum := make([]int, 32)

	for _, num := range nums {
		bin := strconv.FormatInt(int64(num), 2)

		if num < 0 {
			l := len(bin)
			pos := 0
			for i := l - 1; i >= 1; i-- {
				n, err := strconv.Atoi(string(bin[i]))
				if err != nil {
					panic(err)
				}

				negBinSum[pos] += n
				pos += 1
			}
		} else {
			l := len(bin)
			pos := 0
			for i := l - 1; i >= 0; i-- {
				n, err := strconv.Atoi(string(bin[i]))
				if err != nil {
					panic(err)
				}

				posBinSum[pos] += n
				pos += 1
			}
		}
	}

	var ans float64
	for i := 0; i < 32; i++ {
		x := posBinSum[i] % 3
		ans += float64(x) * math.Pow(2, float64(i))
	}

	if ans != 0 {
		return int(ans)
	}

	for i := 0; i < 32; i++ {
		x := negBinSum[i] % 3
		ans += float64(x) * math.Pow(2, float64(i))
	}

	return int(ans) * -1
}
