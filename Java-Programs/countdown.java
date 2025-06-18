import java.util.Scanner;
import java.util.Timer;
import java.util.TimerTask;

class countdown {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter # of seconds for countdown: ");
        int response = sc.nextInt();

        Timer timer = new Timer();
        TimerTask task = new TimerTask() {

            int count = response;

            @Override
            public void run() {

                System.out.println(count);
                count--;
                if (count < 0) {
                    System.out.println("Countdown Finished");
                    timer.cancel();
                }
            }
        };

        timer.schedule(task, 0, 1000); // Task, delay, period.
        sc.close();
    }
}
