import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

class hangman {
    public static void main(String args[]) {
        // JAVA Hangman Game.

        String filePath = "word.txt";
        ArrayList<String> words = new ArrayList<>();

        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                words.add(line.trim());
            }
        } catch (IOException e) {
            System.out.println("Something went Wrong...");
        }

        Random rm = new Random();

        String word = words.get(rm.nextInt(words.size()));

        Scanner sc = new Scanner(System.in);

        ArrayList<Character> wordState = new ArrayList<>();
        int wrongGuesses = 0;

        for (int i = 0; i < word.length(); i++) {
            wordState.add('_');
        }

        System.out.println("-------------------------");
        System.out.println(" Welcome to Java Hangman!");
        System.out.println("-------------------------");

        while (wrongGuesses < 6) {

            System.out.print("Word: ");
            for (char c : wordState) {
                System.out.print(c + " ");
            }
            System.out.println();

            System.out.print("Guess a letter: ");
            char guess = sc.next().toLowerCase().charAt(0);

            if (word.indexOf(guess) >= 0) {
                System.out.println("Correct Guess!\n");

                for (int i = 0; i < word.length(); i++) {
                    if (word.charAt(i) == guess) {
                        wordState.set(i, guess);
                    }
                }
                if (!wordState.contains('_')) {
                    break;
                }
            } else {
                System.out.println("Wrong Guess!\n");
                wrongGuesses++;
            }
            System.out.println(getHangmanArt(wrongGuesses));
        }
        if (wrongGuesses >= 6) {
            System.out.println(getHangmanArt(wrongGuesses));
            System.out.println("Game Over!");

        } else {
            System.out.println(getHangmanArt(wrongGuesses));
            System.out.println("Congratulations! You won!");

        }
        System.out.println("The word was: " + word);

        sc.close();

    }

    static String getHangmanArt(int wrongGuesses) {
        return switch (wrongGuesses) {
            case 0 -> """



                    """;

            case 1 -> """
                     O


                    """;

            case 2 -> """
                     O
                     |

                    """;

            case 3 -> """
                     O
                     |\\

                    """;

            case 4 -> """
                     O
                    /|\\

                    """;

            case 5 -> """
                     O
                    /|\\
                      \\
                    """;

            case 6 -> """
                     O
                    /|\\
                    / \\
                    """;

            default -> "";
        };
    }
}
