package main

import (
	"fmt"
	"sort"
)

// primeFactors đếm số lượng ước số nguyên tố khác nhau của n
func primeFactors(n int) int {
	factors := make(map[int]bool)
	for i := 2; i*i <= n; i++ {
		for n%i == 0 {
			factors[i] = true
			n /= i
		}
	}
	if n > 1 {
		factors[n] = true
	}
	return len(factors)
}

func maximumScore(nums []int, k int) int {
	mod := int(1e9 + 7)
	n := len(nums)
	arr := make([][3]int, n)
	for i, x := range nums {
		arr[i] = [3]int{i, primeFactors(x), x}
	}

	left := make([]int, n)
	right := make([]int, n)
	for i := range left {
		left[i] = -1
		right[i] = n
	}

	// Tìm left
	stack := []int{}
	for i, data := range arr {
		for len(stack) > 0 && arr[stack[len(stack)-1]][1] < data[1] {
			stack = stack[:len(stack)-1]
		}
		if len(stack) > 0 {
			left[i] = stack[len(stack)-1]
		}
		stack = append(stack, i)
	}

	// Tìm right
	stack = []int{}
	for i := n - 1; i >= 0; i-- {
		data := arr[i]
		for len(stack) > 0 && arr[stack[len(stack)-1]][1] <= data[1] {
			stack = stack[:len(stack)-1]
		}
		if len(stack) > 0 {
			right[i] = stack[len(stack)-1]
		}
		stack = append(stack, i)
	}

	// Sắp xếp giảm dần theo giá trị
	sort.Slice(arr, func(i, j int) bool {
		return arr[i][2] > arr[j][2]
	})

	ans := 1
	for _, data := range arr {
		i, _, x := data[0], data[1], data[2]
		l, r := left[i], right[i]
		cnt := (i - l) * (r - i)
		if cnt <= k {
			ans = ans * modPow(x, cnt, mod) % mod
			k -= cnt
		} else {
			ans = ans * modPow(x, k, mod) % mod
			break
		}
	}
	return ans
}

// modPow tính (base^exp) % mod bằng phương pháp lũy thừa nhanh
func modPow(base, exp, mod int) int {
	res := 1
	for exp > 0 {
		if exp%2 == 1 {
			res = res * base % mod
		}
		base = base * base % mod
		exp /= 2
	}
	return res
}

func main() {
	nums := []int{8, 12, 6, 4, 3}
	k := 3
	fmt.Println(maximumScore(nums, k)) // Kết quả mong đợi
}
