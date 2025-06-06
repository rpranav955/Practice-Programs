import java.util.Scanner;

public class week {
    public static void main(String a[]) {

        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the number of your day:");
        int n = scanner.nextInt();

        switch (n) {
            case 1:
                System.out.println("Your day : Sunday");
                break;
            case 2:
                System.out.println("Your day : Monday");
                break;
            case 3:
                System.out.println("Your day : Tuesday");
                break;
            case 4:
                System.out.println("Your day : Wednesday");
                break;
            case 5:
                System.out.println("Your day : Thursday");
                break;
            case 6:
                System.out.println("Your day : Friday");
                break;
            case 7:
                System.out.println("Your day : Saturday");
                break;
            default:
                System.out.println("Enter a valid number (1-7)");

            scanner.close();
            
        }
    }
}
