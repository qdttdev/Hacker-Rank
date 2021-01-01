import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the kaprekarNumbers function below.
    static void kaprekarNumbers(int p, int q) 
    {
        int count = 0;
        int smallSum = 0;
        BigInteger bigIntVal = new BigInteger("0");
        BigInteger bigSum = new BigInteger("0");
        BigInteger n1;
        BigInteger n2;
        String strVal, s1, s2;

        for(int i = p; i <= q; i++)
        {
            // Squares the integer
            bigIntVal = BigInteger.valueOf(i).multiply(BigInteger.valueOf(i));
            strVal = bigIntVal.toString();           

            // If the integer is greater than 10, then split strings into halves
            if(bigIntVal.compareTo(BigInteger.valueOf(10)) > 0)
            {
                // Split the string into halves
                s1 = strVal.substring(0, strVal.length()/2);
                s2 = strVal.substring(strVal.length()/2, strVal.length());

                // Convert them back to BigInteger
                n1 = new BigInteger(s1);
                n2 = new BigInteger(s2);

                // Sum them
                bigSum = n1.add(n2);
            }
            else // Else, just convert them into integers
            {
                smallSum = strVal.charAt(0) - '0';
            }

            if(bigSum.compareTo(BigInteger.valueOf(i)) == 0 || smallSum == i)
            {
                System.out.print(i + " ");
                count++;
            }
        }

        if(count == 0)
        {
            System.out.println("INVALID RANGE");
        }
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int p = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        kaprekarNumbers(p, q);

        scanner.close();
    }
}
