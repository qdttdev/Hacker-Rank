import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int i = scan.nextInt();
        double d = scan.nextDouble();

        String str = "";
        while(scan.hasNext())
        {
            str = scan.nextLine();
        }
        scan.close();

        System.out.println("String: " + str);
        System.out.println("Double: " + d);
        System.out.println("Int: " + i);
    }
}
