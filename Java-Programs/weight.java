import java.util.Scanner;

class weight {
    public static void main(String a[]) {

        // Weight Conversion Program

        Scanner sc = new Scanner(System.in);

        System.out.println("Option (1) Convert lbs to kgs\nOption (2) Convert kgs to lbs");
        System.out.print("Choose Option(1/2): ");
        int choice = sc.nextInt();

        if (choice == 1) {
            System.out.println();
            System.out.print("Enter Weight in lbs: ");
            double lbs = sc.nextDouble();
            double result = lbs * 0.453592;

            System.out.printf("\n%.2flbs ---------> %.2fkgs\n", lbs, result);
        } else if (choice == 2) {
            System.out.println();
            System.out.print("Enter Weight in kgs: ");
            double kgs = sc.nextDouble();
            double result = kgs * 2.20462;

            System.out.printf("\n%.2fkgs ---------> %.2flbs\n", kgs, result);
        } else {
            System.out.println();
            System.out.println("Please enter a valid choice!");
        }
        sc.close();

    }
}
