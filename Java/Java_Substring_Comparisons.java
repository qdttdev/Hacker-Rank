import java.util.Scanner;

public class Solution {

    public static String getSmallestAndLargest(String s, int k) {
        String smallest = "";
        String largest = "";
        
        // Complete the function
        // 'smallest' must be the lexicographically smallest substring of length 'k'
        // 'largest' must be the lexicographically largest substring of length 'k'
        
        String[] elemAr;
        elemAr = new String[s.length()-k+1];

        for(int i = 0, j = k; j < s.length()+1; i++, j++)
        {
            elemAr[i] = s.substring(i, j);
        }

        java.util.Arrays.sort(elemAr);
        smallest = elemAr[0];
        largest = elemAr[elemAr.length-1]; 

        // --------------------------------------------------------------------
        // Solution for the pupose of Comparisons without importing Arrays.sort
        // --------------------------------------------------------------------
        // smallest = elemAr[0];
        // largest = elemAr[0];

        // for(int i = 0; i < elemAr.length; i++)
        // {
        //     if(smallest.compareTo(elemAr[i]) >= 0) // -1, 0, 1 = lt, eq, gt
        //     {
        //         smallest = elemAr[i];
        //     }

        //    if(largest.compareTo(elemAr[i]) <= 0) // -1, 0, 1 = lt, eq, gt
        //     {
        //         largest = elemAr[i];
        //     } 
        // }               
        
        return smallest + "\n" + largest;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.next();
        int k = scan.nextInt();
        scan.close();
      
        System.out.println(getSmallestAndLargest(s, k));
    }
}