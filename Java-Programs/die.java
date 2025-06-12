import java.util.Random;
import java.util.Scanner;

class die {
    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        Random random = new Random();

        int numOfDice, total = 0;

        System.out.print("Enter the number of Dice to be rolled: ");
        numOfDice = sc.nextInt();

        if (numOfDice > 0) {

            for (int i = 0; i < numOfDice; i++) {
                int roll = random.nextInt(1, 7);

                System.out.println("You rolled: " + roll);
                printDie(roll);
                total += roll;
            }

        } else {
            System.out.println("Invalid input.");
        }

        System.out.println("Total: " + total);

        sc.close();

    }

    static void printDie(int roll) {
        String die1 = """
                ----------
                |        |
                |    0   |
                |        |
                ----------
                """;
        String die2 = """
                ----------
                | 0      |
                |        |
                |      0 |
                ----------
                """;

        String die3 = """
                ----------
                | 0      |
                |    0   |
                |      0 |
                ----------
                """;

        String die4 = """
                ----------
                | 0    0 |
                |        |
                | 0    0 |
                ----------
                """;

        String die5 = """
                ----------
                | 0    0 |
                |    0   |
                | 0    0 |
                ----------
                """;
        String die6 = """
                ----------
                | 0    0 |
                | 0    0 |
                | 0    0 |
                ----------
                """;
        switch (roll) {
            case 1 -> System.out.println(die1);
            case 2 -> System.out.println(die2);
            case 3 -> System.out.println(die3);
            case 4 -> System.out.println(die4);
            case 5 -> System.out.println(die5);
            case 6 -> System.out.println(die6);
            default -> System.out.println("Invalid Roll.");
        }
    }
}
