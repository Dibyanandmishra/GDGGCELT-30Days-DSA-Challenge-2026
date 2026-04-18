// Left Rotation

// A left rotation operation on an array shifts each of the array's elements unit to the left. For example, if 2 left rotations are performed on array , then the array would become . Note that the lowest index item moves to the end of the array in a rotation. This is called a circular array because the end of the array wraps around to the beginning. Given an array of integers and a number, , perform  left rotations on the array. Return the updated array to be printed as a single line of space-separated integers.

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
    
    public static List<Integer> rotateLeft(int d, List<Integer> arr) {
        if (arr == null || arr.isEmpty()) {
            return new ArrayList<>();
        }

        int n = arr.size();
        d = ((d % n) + n) % n;

        List<Integer> result = new ArrayList<>();

        for(int i = d; i < n; i++) {
            result.add(arr.get(i));
        }

        for(int i = 0; i < d; i++) {      
            result.add(arr.get(i));   
        }

        return result;
    }

}

public class Day01 {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        String outputPath = System.getenv("OUTPUT_PATH");
        BufferedWriter bufferedWriter = (outputPath == null || outputPath.isEmpty())
            ? new BufferedWriter(new OutputStreamWriter(System.out))
            : new BufferedWriter(new FileWriter(outputPath));

        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int n = Integer.parseInt(firstMultipleInput[0]);

        int d = Integer.parseInt(firstMultipleInput[1]);

        List<Integer> arr = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        List<Integer> result = Result.rotateLeft(d, arr);

        bufferedWriter.write(
            result.stream()
                .map(Object::toString)
                .collect(joining(" "))
            + "\n"
        );

        bufferedReader.close();
        bufferedWriter.close();
    }
}

