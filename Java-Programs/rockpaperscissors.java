// Rock, Paper, Scissors

import java.util.Random;
import java.util.Scanner;

class rockpaperscissors {
    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        Random random = new Random();
        int yourChoiceNumber = -1;
        int score = 0;
        Boolean gameOver = false;
        while (!gameOver) {
            String[] option = { "rock", "paper", "scissors" };
            int computerChoice = random.nextInt(0, 3);

            System.out.print("Choose (Rock/ Paper/ Scissors): ");
            String yourChoice = sc.nextLine();
            System.out.println();

            switch (yourChoice.toLowerCase()) {
                case "rock" -> yourChoiceNumber = 0;
                case "paper" -> yourChoiceNumber = 1;
                case "scissors" -> yourChoiceNumber = 2;
                default -> yourChoiceNumber = -1;
            }

            if (yourChoiceNumber == computerChoice) {
                System.out.println("Computer chose: " + option[computerChoice]);
                System.out.println("Its a Draw!");
            } else if (yourChoiceNumber == -1) {
                System.out.println("Invalid Input!");
            } else

            {
                System.out.println("Computer chose: " + option[computerChoice]);
                switch (yourChoiceNumber) {
                    case 0 -> {
                        if (computerChoice == 1) {
                            System.out.println("You Lost!");
                        } else {
                            System.out.println("You Won!");
                            score++;
                        }
                    }
                    case 1 -> {
                        if (computerChoice == 2) {
                            System.out.println("You Lost!");
                        } else {
                            System.out.println("You Won!");
                            score++;
                        }
                    }
                    case 2 -> {
                        if (computerChoice == 0) {
                            System.out.println("You Lost!");
                        } else {
                            System.out.println("You Won!");
                            score++;
                        }
                    }
                }
            }
            System.out.println("End the game?");
            System.out.print("(Yes / No): ");
            String flag = sc.nextLine();
            if (flag.toLowerCase().equals("yes")) {
                gameOver = true;
            }
            System.out.println();
        }
        System.out.println("GAME OVER");
        System.out.println("Total Score: " + score);

        sc.close();
    }
}
