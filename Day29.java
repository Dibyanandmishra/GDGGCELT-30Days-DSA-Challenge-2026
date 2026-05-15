// Array Pairs

import java.util.*;
import java.io.*;

public class Day29 {
    static class FastReader {
        private InputStream in;
        private byte[] buffer = new byte[1024 * 16];
        private int ptr = 0;
        private int len = 0;

        public FastReader(InputStream in) {
            this.in = in;
        }

        private int read() {
            if (ptr < len) return buffer[ptr++];
            ptr = 0;
            try {
                len = in.read(buffer);
            } catch (IOException e) {
                return -1;
            }
            if (len <= 0) return -1;
            return buffer[ptr++];
        }

        public String next() {
            int b = read();
            while (b != -1 && b <= 32) b = read();
            if (b == -1) return null;
            StringBuilder sb = new StringBuilder();
            while (b > 32) {
                sb.append((char) b);
                b = read();
            }
            return sb.toString();
        }

        public int nextInt() {
            int b = read();
            while (b != -1 && b <= 32) b = read();
            if (b == -1) return 0;
            int neg = 1;
            if (b == '-') {
                neg = -1;
                b = read();
            }
            int res = 0;
            while (b >= '0' && b <= '9') {
                res = res * 10 + (b - '0');
                b = read();
            }
            return res * neg;
        }
    }

    static int[] LC, RC, treeCount;
    static int nodes_cnt = 0;

    static int update(int prev, int l, int r, int x) {
        int curr = ++nodes_cnt;
        treeCount[curr] = treeCount[prev] + 1;
        LC[curr] = LC[prev];
        RC[curr] = RC[prev];
        if (l == r) return curr;
        int mid = (l + r) / 2;
        if (x <= mid) LC[curr] = update(LC[prev], l, mid, x);
        else RC[curr] = update(RC[prev], mid + 1, r, x);
        return curr;
    }

    static int query(int node, int l, int r, int qr) {
        if (node == 0 || qr < l) return 0;
        if (r <= qr) return treeCount[node];
        int mid = (l + r) / 2;
        int res = query(LC[node], l, mid, qr);
        if (qr > mid) res += query(RC[node], mid + 1, r, qr);
        return res;
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader(System.in);
        String line = fr.next();
        if (line == null) return;
        int n = Integer.parseInt(line);
        int[] val = new int[n + 1];
        int[] sorted = new int[n];
        for (int i = 1; i <= n; i++) {
            val[i] = fr.nextInt();
            sorted[i - 1] = val[i];
        }

        // Coordinate Compression
        Arrays.sort(sorted);
        int m = 0;
        if (n > 0) {
            m = 1;
            for (int i = 1; i < n; i++) {
                if (sorted[i] != sorted[i - 1]) sorted[m++] = sorted[i];
            }
        }

        // Persistent Segment Tree
        // Max nodes ~ N * log2(N)
        int max_nodes = n * 25; 
        LC = new int[max_nodes];
        RC = new int[max_nodes];
        treeCount = new int[max_nodes];
        int[] roots = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            int rank = Arrays.binarySearch(sorted, 0, m, val[i]) + 1;
            roots[i] = update(roots[i - 1], 1, m, rank);
        }

        // Monotonic Stack for boundaries
        int[] left = new int[n + 1];
        int[] right = new int[n + 1];
        int[] stack = new int[n + 1];
        int top = 0;

        for (int i = 1; i <= n; i++) {
            while (top > 0 && val[stack[top]] < val[i]) top--;
            left[i] = (top == 0) ? 0 : stack[top];
            stack[++top] = i;
        }
        top = 0;
        for (int i = n; i >= 1; i--) {
            while (top > 0 && val[stack[top]] <= val[i]) top--;
            right[i] = (top == 0) ? n + 1 : stack[top];
            stack[++top] = i;
        }

        long totalPairs = 0;
        for (int i = 1; i <= n; i++) {
            int l_bound = left[i] + 1;
            int r_bound = right[i] - 1;

            if (i - l_bound <= r_bound - i) {
                for (int j = l_bound; j <= i; j++) {
                    int threshold = val[i] / val[j];
                    int rank_t = Arrays.binarySearch(sorted, 0, m, threshold);
                    if (rank_t < 0) rank_t = -rank_t - 2;
                    if (rank_t >= 0) {
                        int ql = (j == i) ? i + 1 : i;
                        int qr = r_bound;
                        if (ql <= qr) {
                            totalPairs += query(roots[qr], 1, m, rank_t + 1) - query(roots[ql - 1], 1, m, rank_t + 1);
                        }
                    }
                }
            } else {
                for (int k = i; k <= r_bound; k++) {
                    int threshold = val[i] / val[k];
                    int rank_t = Arrays.binarySearch(sorted, 0, m, threshold);
                    if (rank_t < 0) rank_t = -rank_t - 2;
                    if (rank_t >= 0) {
                        int ql = l_bound;
                        int qr = (k == i) ? i - 1 : i;
                        if (ql <= qr) {
                            totalPairs += query(roots[qr], 1, m, rank_t + 1) - query(roots[ql - 1], 1, m, rank_t + 1);
                        }
                    }
                }
            }
        }
        System.out.println(totalPairs);
    }
}
