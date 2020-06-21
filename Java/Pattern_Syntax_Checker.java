import java.util.Scanner;
import java.util.regex.*;

public class Solution
{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);

        // Write your code
        int testCases = in.nextInt();
        in.nextLine(); // omit the rest of the line

		for(int i = 0; i < testCases; i++)
        {
			String pattern = in.nextLine();              

            try
            {
                Pattern pat = Pattern.compile(pattern);
                System.out.println("Valid");
            }
            catch(Exception e)
            {
                System.out.println("Invalid");
            }
		}
	}
}



