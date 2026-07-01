func checkInclusion(s1 string, s2 string) bool {
    if len(s1) > len(s2) {
        return false
    }

    need := make([]int, 26)
    window := make([]int, 26)

    for _, ch := range s1 {
        need[ch-'a']++
    }

    for i := 0; i < len(s2); i++ {
        window[s2[i]-'a']++

        if i >= len(s1) {
            window[s2[i-len(s1)]-'a']--
        }

        if equal(need, window) {
            return true
        }
    }

    return false
}

func equal(a, b []int) bool {
    for i := 0; i < 26; i++ {
        if a[i] != b[i] {
            return false
        }
    }
    return true
}
