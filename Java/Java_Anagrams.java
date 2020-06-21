import java.util.Scanner;

public class Solution {

    static boolean isAnagram(String a, String b) {

        if(a.length() != b.length())
        {
            return false;
        }
        else
        {   
            // Case insensitivity and removal of white spaces     
            a = (a.toUpperCase()).trim();
            b = (b.toUpperCase()).trim();

            // Turn 2 strings into char arrays for sorting
            char[] aArray = new char[a.length()];
            char[] bArray = new char[b.length()];

            for(int i = 0; i < aArray.length; i++)
            {
                aArray[i] = a.charAt(i);
                bArray[i] = b.charAt(i);
            }

            java.util.Arrays.sort(aArray);
            java.util.Arrays.sort(bArray);

            return java.util.Arrays.equals(aArray, bArray);
        }       
    }

    public static void main(String[] args) {
    
        Scanner scan = new Scanner(System.in);
        String a = scan.next();
        String b = scan.next();
        scan.close();
        boolean ret = isAnagram(a, b);
        System.out.println( (ret) ? "Anagrams" : "Not Anagrams" );
    }
}