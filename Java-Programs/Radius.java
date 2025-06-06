import java.util.Scanner;

class Radius {
    public static void main(String args[]) {

        // Program to find Area and Circumference of a Circle with a given radius.
        // Also finds Volume of the Sphere with that radius.

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter your Radius: ");
        int r = sc.nextInt();

        System.out.printf("Area: %.2f\n", (Math.PI * Math.pow(r, 2)));
        System.out.printf("Circumference: %.2f\n", (2 * Math.PI * r));
        System.out.printf("Volume: %.2f\n", ((4.0 / 3.0) * Math.PI * Math.pow(r, 3)));

        sc.close();

    }
}
