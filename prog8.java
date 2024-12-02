import java.util.Scanner;

public class LeakyBucket {
    static int min(int x, int y) {
        return (x < y) ? x : y;
    }

    public static void main(String[] args) {
        int drop = 0, mini, nsec, cap, count = 0, i, process;
        int inp[] = new int[25];

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the Bucket Size:");
        cap = sc.nextInt();

        System.out.println("Enter the Operation Rate:");
        process = sc.nextInt();

        System.out.println("Enter the Number of Seconds to Simulate:");
        nsec = sc.nextInt();

        for (i = 0; i < nsec; i++) {
            System.out.print("Enter the Size of the Packet Entering at " + (i + 1) + " sec: ");
            inp[i] = sc.nextInt();
        }

        System.out.println("\nSecond | Packet Received | Packet Sent | Packet Left | Packet Dropped");
        System.out.println("-------|-----------------|-------------|-------------|---------------");

        for (i = 0; i < nsec; i++) {
            count += inp[i];

            if (count > cap) {
                drop = count - cap;
                count = cap;
            }

            mini = min(count, process);
            count -= mini;

            System.out.printf("%6d | %15d | %11d | %11d | %15d\n", i + 1, inp[i], mini, count, drop);
            drop = 0;
        }

        while (count != 0) {
            if (count > cap) {
                drop = count - cap;
                count = cap;
            }

            mini = min(count, process);
            count -= mini;

            System.out.printf("%6d | %15d | %11d | %11d | %15d\n", ++i, 0, mini, count, drop);
        }

        sc.close();
    }
}
