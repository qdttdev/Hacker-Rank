import java.util.*;
import java.io.*;

class Solution{
    public static void main(String []argh){
        Scanner in = new Scanner(System.in);
        int t=in.nextInt();

        double result = 0;
        double temp = 0;

        for(int i=0;i<t;i++){
            int a = in.nextInt();
            int b = in.nextInt();
            int n = in.nextInt();

            temp = a;

            for(int j = 0; j < n; j++)
            {
                result = temp + Math.pow(2,j) * b;
                System.out.printf("%.0f ", result);
                temp = result;
            }

            System.out.println();

        }

        in.close();

        // FOR VISUALIZATION

        // int s0  = a   + Math.pow(2,0)  * b;
        // int s1  = s0  + Math.pow(2,1)  * b;
        // int s2  = s1  + Math.pow(2,2)  * b;
        // int s3  = s2  + Math.pow(2,3)  * b;
        // int s4  = s3  + Math.pow(2,4)  * b;
        // int s5  = s4  + Math.pow(2,5)  * b;
        // int s6  = s5  + Math.pow(2,6)  * b;
        // int s7  = s6  + Math.pow(2,7)  * b;
        // int s8  = s7  + Math.pow(2,8)  * b;
        // int s9  = s8  + Math.pow(2,9)  * b;
        // int s10 = s9  + Math.pow(2,10) * b;
        // int s11 = s10 + Math.pow(2,11) * b;
        // int s12 = s11 + Math.pow(2,12) * b;
        // int s13 = s12 + Math.pow(2,13) * b;
        // int s14 = s13 + Math.pow(2,14) * b;       
    }
}
