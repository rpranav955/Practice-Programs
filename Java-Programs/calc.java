import java.util.Scanner;

class calc {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter your first number: ");

        double num1 = sc.nextDouble();

        System.out.print("Choose the Operator (+, -, *, /, ^): ");
        char op = sc.next().charAt(0);

        System.out.print("Enter your second number: ");
        double num2 = sc.nextDouble();

        double result;
        switch (op) {
            case '+' -> {
                result = num1 + num2;
                System.out.printf("%.2f + %.2f = %.2f\n", num1, num2, result);
            }
            case '-' -> {
                result = num1 - num2;
                System.out.printf("%.2f - %.2f = %.2f\n", num1, num2, result);
            }
            case '*' -> {
                result = num1 * num2;
                System.out.printf("%.2f * %.2f = %.2f\n", num1, num2, result);
            }
            case '/' -> {
                if (num2 == 0) {
                    System.out.println("Cannot divide by 0!");
                } else {
                    result = num1 / num2;
                    System.out.printf("%.2f / %.2f = %.2f\n", num1, num2, result);
                }
            }
            case '^' -> {
                result = Math.pow(num1, num2);
                System.out.printf("%.2f ^ %.2f = %.2f\n", num1, num2, result);
            }
            default -> System.out.println("Not a valid choice!");
        }

        sc.close();
    }
}
