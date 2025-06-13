
// Gambling Machine
import java.util.Random;
import java.util.Scanner;

class gambling {
    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        Random rm = new Random();

        char currency = '$';
        int currentBalance = 100, bet = 0;
        System.out.println("Your Current Balance: " + currency + currentBalance);
        Boolean reroll = true;
        while (reroll) {

            System.out.println("Place your bet: ");
            bet = sc.nextInt();
            sc.nextLine();

            while (!(bet > 0)) {
                if (!(bet > 0)) {
                    System.out.println("Bet cant be Negative.");
                    System.out.println("Place your bet: ");
                    bet = sc.nextInt();
                    sc.nextLine();
                }
            }

            int[] count = { 0, 0, 0, 0, 0 };
            int flag = 0;

            System.out.println("Spinning...");
            String[] choices = { "🤡", "💥", "👾", "👻", "💋" };
            String[] spin = { "", "", "" };
            for (String n : spin) {
                n = choices[rm.nextInt(choices.length)];
                if (n.equals("🤡"))
                    count[0]++;
                if (n.equals("💥"))
                    count[1]++;
                if (n.equals("👾"))
                    count[2]++;
                if (n.equals("👻"))
                    count[3]++;
                if (n.equals("💋"))
                    count[4]++;
                System.out.print(n + "  ");
            }
            System.out.println();
            for (int i = 0; i < choices.length; i++) {
                if (count[i] == 3) {
                    flag = 2;
                    break;
                } else if (count[i] == 2) {
                    flag = 1;
                    break;
                } else {
                    flag = 0;
                }
            }
            switch (flag) {
                case 2 -> {
                    System.out.println("JACKPOT!");
                    System.out.println("You won: " + currency + (3 * bet));
                    currentBalance += (3 * bet);
                    System.out.println("Your Current Balance: " + currentBalance);
                }
                case 1 -> {
                    System.out.println("You won: " + currency + (2 * bet));
                    currentBalance += (2 * bet);
                    System.out.println("Your Current Balance: " + currentBalance);
                }
                case 0 -> {
                    System.out.println("You Lost: " + currency + (bet));
                    currentBalance -= bet;
                    System.out.println("Your Current Balance: " + currentBalance);
                }
            }
            System.out.println("Reroll? (Yes/No): ");
            String yesorno = sc.nextLine();
            if (yesorno.toLowerCase().equals("no"))
                reroll = false;
        }

        if (currentBalance >= 0) {
            System.out.println("You Made: " + currency + currentBalance);
            System.out.println("Congrats🎉🎉");
        } else {
            System.out.println("You Lost: " + currency + currentBalance);
            System.out.println("WOMP WOMP 😂😂");
        }

        sc.close();
    }
}
