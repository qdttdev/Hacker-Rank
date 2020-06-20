import java.util.*;
import java.text.*;

public class Solution {
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double payment = scanner.nextDouble();
        scanner.close();
        
// Some countries have built-in locales (Locale Constants)
//      Example: Locale.US

        Locale usLocale     = Locale.US;
        Locale indiaLocale  = new Locale("en", "IN");
        Locale chinaLocale  = Locale.CHINA;
        Locale franceLocale = Locale.FRANCE;

// getCurrencyInstance(Locale inLocale)
//      Returns a currency format for the specified locale.

// To format a number for the current Locale, use one of the factory class methods:
//      myString = NumberFormat.getInstance().format(myNumber);

        String us       = NumberFormat.getCurrencyInstance(usLocale).format(payment);
        String india    = NumberFormat.getCurrencyInstance(indiaLocale).format(payment);
        String china    = NumberFormat.getCurrencyInstance(chinaLocale).format(payment);
        String france   = NumberFormat.getCurrencyInstance(franceLocale).format(payment);
        
        System.out.println("US: " + us);
        System.out.println("India: " + india);
        System.out.println("China: " + china);
        System.out.println("France: " + france);
    }
}
