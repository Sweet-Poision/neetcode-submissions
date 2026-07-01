class Solution {
    public boolean checkInclusion(String s1, String s2) {
        if(s1.length() > s2.length()) return false;
        int[] n = new int[26];
        int[] w = new int[26];
        for(char c: s1.toCharArray()) n[c-'a']++;
        for(int i = 0; i < s2.length(); ++i) {
            w[s2.charAt(i) - 'a']++;
            if(i >= s1.length()) 
                w[s2.charAt(i - s1.length()) - 'a']--;
            if(Arrays.equals(w, n)) return true;
        }
        return false;
    }
}
