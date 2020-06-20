

    static int B, H;
    static boolean flag = true;

    // A static initialization blocks allows more complex initialization
    static {

        Scanner scanner = new Scanner(System.in);
        B = scanner.nextInt();
        H = scanner.nextInt();
        scanner.close();

        try 
        {
            if (B <= 0 || H <= 0)
            {
                throw new Exception("Breadth and height must be positive");
            }        
        }     
        catch (Exception e) 
        {
            System.out.println(e);
            System.exit(0); // exception handled so return 0
        }    

    } // end static
    

// RESOURCE
// Static Initialization Block: https://stackoverflow.com/questions/9379426/java-when-is-a-static-initialization-block-useful
// System.exit(): https://stackoverflow.com/questions/2434592/difference-in-system-exit0-system-exit-1-system-exit1-in-java

