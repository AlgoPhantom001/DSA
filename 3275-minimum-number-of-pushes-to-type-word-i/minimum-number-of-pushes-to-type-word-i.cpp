class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int pushes = 0;
        
        for (int i = 0; i < n; i++) {
            // (i / 8) gives the group index: 
            // 0..7 -> +1 push, 8..15 -> +2 pushes, etc.
            pushes += (i / 8) + 1;
        }
        
        return pushes;
    }
};