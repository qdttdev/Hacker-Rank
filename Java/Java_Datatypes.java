import java.util.*;
import java.io.*;

class Solution{
    public static void main(String []argh)
    {
        Scanner sc = new Scanner(System.in);
        int t=sc.nextInt();

        for(int i=0;i<t;i++)
        {
            try
            {
                long x=sc.nextLong();
                System.out.println(x+" can be fitted in:");
                if(x>=-128 && x<=127)System.out.println("* byte");
                
                // Short: -32,768 and a maximum value of 32,767
                if(x >= -32768 && x <= 32767)
                {
                    System.out.println("* short");
                }

                // Int: -2^31 and a maximum value of 2^31 - 1
                if(x >= Math.pow(-2,31) && x <= (Math.pow(2,31)-1))
                {
                    System.out.println("* int");
                }

                // Long: -2^63 and a maximum value of 2^63 - 1.
                if(x >= Math.pow(-2,63) && x <= (Math.pow(2,63)-1))
                {
                    System.out.println("* long");
                }
            }
            catch(Exception e)
            {
                System.out.println(sc.next()+" can't be fitted anywhere.");
            }
        }
    }
}



