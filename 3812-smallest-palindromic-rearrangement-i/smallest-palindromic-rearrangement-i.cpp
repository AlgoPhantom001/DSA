class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        
        // Extract the first half
        string half = s.substr(0, n / 2);
        
        // Sort the first half to make it lexicographically smallest
        sort(half.begin(), half.end());
        
        // Construct the result
        string rev_half = half;
        reverse(rev_half.begin(), rev_half.end());
        
        if (n % 2 != 0) {
            return half + s[n / 2] + rev_half;
        } else {
            return half + rev_half;
        }
    }
};