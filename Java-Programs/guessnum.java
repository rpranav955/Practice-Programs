import java.util.Random;
import java.util.Scanner;

class guessnum {
    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        Random random = new Random();
        int dif, max, attempt = 0;

        System.out.println("Welcome to Number Guessing Game");
        do {

            System.out.println("Choose Difficulty");
            System.out.println("1 -> Easy (1-10)\n2 -> Medium(1-100)\n3 -> Hard(1-1000)");
            dif = sc.nextInt();

        } while (dif > 3 || dif < 1);

        if (dif == 1)
            max = 10;
        else if (dif == 2)
            max = 100;
        else
            max = 1000;

        int guess, randomNumber;

        randomNumber = random.nextInt(1, max + 1);

        do {
            System.out.println();
            System.out.print("Enter your Guess: ");
            guess = sc.nextInt();
            attempt++;

            if (guess > 0 && guess < max + 1) {
                if (guess < randomNumber) {
                    System.out.println("TOO LOW...");
                } else if (guess > randomNumber) {
                    System.out.println("TOO HIGH...");
                } else {
                    System.out.println();
                    System.out.println("Correct Guess" + "The number was " + guess);
                    System.out.println("# of attempts: " + attempt);
                }
            } else {
                System.out.printf("Please Guess number from the range (1-%d)\n", max);
            }

        } while (guess != randomNumber);

    }
}
