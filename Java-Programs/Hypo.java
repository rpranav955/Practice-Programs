import java.util.Scanner;

class demo {
    public static void main(String args[]) {

        // HYPOTENUSE c = Math.sqrt(a^2 + b^2).

        Scanner sc = new Scanner(System.in);

        double a, b, result;

        System.out.println("Enter your first side: ");
        a = sc.nextDouble();

        System.out.println("Enter your first side: ");
        b = sc.nextDouble();

        result = Math.sqrt(Math.pow(a, 2) + Math.pow(b, 2));

        System.out.println("Hypotenuse: " + result);

        sc.close();

    }
}
