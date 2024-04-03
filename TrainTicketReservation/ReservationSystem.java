import java.util.Scanner;

public class ReservationSystem {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int noOfCompartments = 1;//input.nextInt();
        Train train = new Train(noOfCompartments);
        int choice = input.nextInt();
        while (choice != 0) {
            
            train.bookTicket();
         choice = input.nextInt();

        }
        input.close();
    }
}
