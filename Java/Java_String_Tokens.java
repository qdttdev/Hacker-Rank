import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine();
        scan.close();       

        // Write code here

        s = s.trim();

        if(s.length() == 0)
        {
            System.out.println("0");
        }
        else
        {           
            String[] sArray = (s.split("[!,?._'@\\s]+"));

            System.out.println(sArray.length);

            for(int i = 0; i < sArray.length; i++)
            {
                System.out.println(sArray[i]);
            }    
        }             
    }
}

// split("[!,?._'@\\s]+"), the "+" acts as &&
// \s = A whitespace character: [ \t\n\x0B\f\r]
// More about Pattern: https://docs.oracle.com/javase/7/docs/api/java/util/regex/Pattern.html