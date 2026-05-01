import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        int[] c = new int[m];

        for (int i = 0; i < m; i++) {
            c[i] = sc.nextInt();
        }

        Arrays.sort(c);

        int maxDist = 0;

        maxDist = c[0];

        for (int i = 1; i < m; i++) {
            int gap = (c[i] - c[i - 1]) / 2;
            maxDist = Math.max(maxDist, gap);
        }

        maxDist = Math.max(maxDist, (n - 1) - c[m - 1]);

        System.out.println(maxDist);
    }
}