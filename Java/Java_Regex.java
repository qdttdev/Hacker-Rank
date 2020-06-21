import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.Scanner;

class Solution{

    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        while(in.hasNext()){
            String IP = in.next();
            System.out.println(IP.matches(new MyRegex().pattern));
        }

    }
}

//Write your code here

class MyRegex 
{ 
    String format_0_255 = "(\\d|\\d\\d|(0|1)\\d\\d|2[0-4]\\d|25[0-5])"; 
    
    String pattern = format_0_255 + "." + format_0_255 + "." + format_0_255 + "." + format_0_255; 
}

// Valid format for each element is:
// 1. Cannot exceed 3 digits
// 2. Cannot exceed 255
// --> Anything from 000 - 255 is valid!

//                                      SHORTCUT        FULL            VISUALIZATION
//                                      --------        ----            -------------
// The element can have 1 digit:        \\d             [0-9]           (0, 1, 2,...)
// The element can have 2 digits:       \\d\\d          [0-9][0-9]      (10, 11, 12,...)  
// The element can have 3 digits:
//      From 000 - 199:                 (0|1)\\d\\d     (0|1)[0-9][0-9] (000,... 099; 100,... 199)
//      From 200 - 255:
//          From 240 - 249:                             2[0-4][0-9]     (200,... 249)
//          From 250 - 255:                             25[0-5]         (250,... 255)


// \d = [0-9] (has to escape \d into \\d)
// | = OR to separate arguments
// () = Grouping

// Learn more about Java Regular Expresions:
// https://www.vogella.com/tutorials/JavaRegularExpressions/article.html