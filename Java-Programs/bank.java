import java.util.Scanner;

class bank {
    public static void main(String args[]) {

        // Banking Program

        Scanner sc = new Scanner(System.in);

        double money = 0;
        int choice = 0;
        do {
            System.out.println("----------------------");
            System.out.println("    Bank of JAVA");
            System.out.println("----------------------");
            System.out.println("Select Option:\n1. Show Balance\n2. Deposit\n3. Withdraw\n4. Exit");
            System.out.println("----------------------");
            choice = sc.nextInt();

            switch (choice) {
                case 1 -> showBalance(money);
                case 2 -> {
                    System.out.print("Enter ammount to be Deposited: ");
                    double am = sc.nextDouble();
                    money += am;
                    deposit(am);
                }
                case 3 -> {
                    System.out.print("Enter ammount to be Withdraw: ");
                    double am = sc.nextDouble();
                    if (money < am) {
                        System.out.println("Insufficient Balance.");
                    } else {
                        money -= am;
                        withdraw(am);
                    }
                }
                case 4 -> System.out.println("Exited.");
                default -> System.out.println("Invalid Input.");
            }
        } while (choice != 4);
    }

    static void showBalance(double money) {
        System.out.printf("Current Balance: %,.2f\n", money);
    }

    static void deposit(double n) {
        System.out.printf("%,.2f deposited to your account.\n", n);
    }

    static void withdraw(double n) {

        System.out.printf("%,.2f withdrawn from your account.\n", n);
    }
}
