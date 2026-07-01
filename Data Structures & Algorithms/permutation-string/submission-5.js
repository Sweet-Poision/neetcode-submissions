class Solution {
    /**
     * @param {string} s1
     * @param {string} s2
     * @return {boolean}
     */
    checkInclusion(s1, s2) {
        if(s1.length > s2.length) return false;
        const n = Array(26).fill(0);
        const w = Array(26).fill(0);
        for(let ch of s1) {
            n[ch.charCodeAt(0)-97]++;
        }
        for(let i = 0; i < s2.length; ++i) {
            w[s2.charCodeAt(i) - 97]++;
            if(i >= s1.length) {
                w[s2.charCodeAt(i - s1.length) - 97]--;
            }
            if(this.arraysEqual(w,n)) return true;
        }
        return false
    }

    arraysEqual(a, b) {
        for(let i = 0; i < 26; ++i) {
            if(a[i] != b[i]) return false;
        }
        return true;
    }
}
