// Substring Diff

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {
    public static int substringDiff(int k, String s1, String s2) {
        int n = s1.length();
        int maxLen = 0;

        for (int d = -n + 1; d < n; d++) {
          int i = Math.max(0, d);
            int j = Math.max(0, -d);
    
            int left = 0, mismatches = 0;
    
            for (int right = 0; i + right < n && j + right < n; right++) {

                if (s1.charAt(i + right) != s2.charAt(j + right)) {
                    mismatches++;
              }

               while (mismatches > k) {
                  if (s1.charAt(i + left) != s2.charAt(j + left)) {
                      mismatches--;
                  }
                  left++;
              }

             maxLen = Math.max(maxLen, right - left + 1);
            }
        }   

        return maxLen;
    }

}

public class Day08 {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = Integer.parseInt(bufferedReader.readLine().trim());

        IntStream.range(0, t).forEach(tItr -> {
            try {
                String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

                int k = Integer.parseInt(firstMultipleInput[0]);

                String s1 = firstMultipleInput[1];

                String s2 = firstMultipleInput[2];

                int result = Result.substringDiff(k, s1, s2);

                bufferedWriter.write(String.valueOf(result));
                bufferedWriter.newLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        bufferedReader.close();
        bufferedWriter.close();
    }
}
