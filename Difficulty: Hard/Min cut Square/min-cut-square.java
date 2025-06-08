import java.util.*;

class Solution {
    public long getKey(int[] remSq, int b) {
        long base = 1, key = 0;
        for (int i = 0; i < b; i++) {
            key += (long) remSq[i] * base;
            base *= (b + 1);
        }
        return key;
    }

    public int minCutUtil(int[] remSq, int a, int b, Map<Long, Integer> memo) {
        long key = getKey(remSq, b);
        if (memo.containsKey(key)) return memo.get(key);

        int maxRemSq = 0, start = 0;
        for (int i = 0; i < b; i++) {
            if (remSq[i] > maxRemSq) {
                maxRemSq = remSq[i];
                start = i;
            }
        }
        if (maxRemSq == 0) return 0;

        int ans = Integer.MAX_VALUE;
        int end = start;
        int[] newRemSq = Arrays.copyOf(remSq, b);

        while (end < b) {
            int squareEdge = end - start + 1;
            if (newRemSq[end] != maxRemSq || newRemSq[end] - squareEdge < 0) break;

            for (int i = start; i <= end; i++) 
                newRemSq[i] = maxRemSq - squareEdge;

            ans = Math.min(ans, 1 + minCutUtil(newRemSq, a, b, memo));
            end++;
        }

        memo.put(key, ans);
        return ans;
    }

    public int minCut(int a, int b) {
        if (a == b) return 1;

        int[] remSq = new int[b];
        Arrays.fill(remSq, a);

        Map<Long, Integer> memo = new HashMap<>();
        return minCutUtil(remSq, a, b, memo);
    }
}
