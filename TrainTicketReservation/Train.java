import java.util.*;

public class Train {
    Scanner input = new Scanner(System.in);
    Compartment[] compartments;
    int unFilledCompartments;
    List<Passenger> waitList;

    public Train(int noOfCompartments) {
        this.compartments = new Compartment[noOfCompartments];
        this.unFilledCompartments = noOfCompartments;
        this.waitList = new ArrayList<>();
        for (int i = 0; i < noOfCompartments; i++) {
            compartments[i] = new Compartment();
        }
    }

    public void bookedTicketsDetails(){
        for (int i = 0; i < compartments.length; i++) {
            System.out.println("Compartment : 1 :-");
            System.out.println("Lower berths Remaining : "+compartments[i].remainingTickets[0]);
        }
    }

    public Passenger getPassenger() {
        System.out.print("Enter your name   :- ");
        String name = input.nextLine();
        System.out.print("Enter your age    :- ");
        int age = input.nextInt();
        input.nextLine();
        System.out.println("M - Male\tF - Female\tT - Others");
        System.out.print("Enter your gender :- ");
        char gender = input.nextLine().charAt(0);
        boolean haveChildren = false;
        System.out.println("L - Lower\tM - Middle\tU - Upper");
        System.out.print("Enter your preferance :- ");
        char preferredBirth = input.nextLine().charAt(0);
        Passenger child = null;
        if (gender == 'F') {
            System.out.println("y- Yes\t n-No");
            System.out.print("Do you have children and Would they travel with you? :- ");
            haveChildren = input.nextLine().charAt(0) == 'y' ? true : false;

            if (haveChildren) {
                System.out.print("Enter your child age :- ");
                int childAge = input.nextInt();
                input.nextLine();
                if (childAge < 6) {
                    System.out.print("Enter your child name :- ");
                    String childName = input.nextLine();
                    System.out.print("Enter your child gender :- ");
                    char childGender = input.nextLine().charAt(0);
                    child = new Passenger(childName, childAge, childGender);
                }
            }
        }
        Passenger passenger;
        if (child == null) {
            passenger = new Passenger(name, age, gender, preferredBirth);
        } else {
            passenger = new Passenger(name, age, gender, preferredBirth, haveChildren, child);
        }
        return passenger;

    }

    public int findIndexCompartment(Compartment compartment) {
        for (int i = 0; i < compartments.length; i++) {
            if (compartment == compartments[i])
                return i + 1;
        }
        return -1;
    }

    public Compartment[] getFreeCompartments() {
        Compartment lowerCompartment = null, middleCompartment = null, upperCompartment = null, racCompartment = null;
        for (Compartment compartment : compartments) {
            if (lowerCompartment == null && compartment.remainingTickets[0] > 0) {
                lowerCompartment = compartment;
            }
            if (middleCompartment == null && compartment.remainingTickets[1] > 0) {
                middleCompartment = compartment;
            }
            if (upperCompartment == null && compartment.remainingTickets[2] > 0) {
                upperCompartment = compartment;
            }
            if (racCompartment == null && compartment.remainingTickets[3] > 0) {
                racCompartment = compartment;
            }
            if (lowerCompartment != null && middleCompartment != null && upperCompartment != null
                    && racCompartment != null) {
                break;
            }
        }
        Compartment[] freeCompartments = { lowerCompartment, middleCompartment, upperCompartment, racCompartment };
        return freeCompartments;
    }

    public void bookTicket() {
        Passenger passenger = getPassenger();
        System.out.println(passenger);
        Passenger[] currCompartment = null;
        Compartment[] freeCompartments = getFreeCompartments();
        if ((passenger.gender == 'F' && passenger.child != null) || passenger.age > 60) {
            passenger.berthPreference = 'L';
        }
        switch (passenger.berthPreference) {
            case 'L':
                if (freeCompartments[0] != null) {
                    passenger.ticketDetails = "" + findIndexCompartment(freeCompartments[0]) + "LOW";
                    freeCompartments[0].remainingTickets[0]--;
                    currCompartment = freeCompartments[0].lower;
                } else if (freeCompartments[1] != null) {
                    passenger.ticketDetails = "" + findIndexCompartment(freeCompartments[1]) + "MID";
                    freeCompartments[1].remainingTickets[1]--;
                    currCompartment = freeCompartments[1].middle;
                } else if (freeCompartments[2] != null) {
                    passenger.ticketDetails = "" + findIndexCompartment(freeCompartments[2]) + "Upp";
                    freeCompartments[2].remainingTickets[2]--;
                    currCompartment = freeCompartments[2].upper;
                } else if (freeCompartments[3] != null) {
                    passenger.ticketDetails = "" + findIndexCompartment(freeCompartments[3]) + "RAC";
                    freeCompartments[3].remainingTickets[3]--;
                    currCompartment = freeCompartments[3].rac;
                }
                break;
            case 'M':
                if (freeCompartments[1] != null) {
                    passenger.ticketDetails = "" + findIndexCompartment(freeCompartments[1]) + "MID";
                    freeCompartments[1].remainingTickets[1]--;
                    currCompartment = freeCompartments[1].middle;
                } else if (freeCompartments[2] != null) {
                    passenger.ticketDetails = "" + findIndexCompartment(freeCompartments[2]) + "UPP";
                    freeCompartments[2].remainingTickets[2]--;
                    currCompartment = freeCompartments[2].upper;
                } else if (freeCompartments[0] != null) {
                    passenger.ticketDetails = "" + findIndexCompartment(freeCompartments[0]) + "LOW";
                    freeCompartments[0].remainingTickets[0]--;
                    currCompartment = freeCompartments[0].lower;
                } else if (freeCompartments[3] != null) {
                    passenger.ticketDetails = "" + findIndexCompartment(freeCompartments[3]) + "RAC";
                    freeCompartments[3].remainingTickets[3]--;
                    currCompartment = freeCompartments[3].rac;
                }
                break;
            case 'U':
                if (freeCompartments[2] != null) {
                    passenger.ticketDetails = "" + findIndexCompartment(freeCompartments[2]) + "UPP";
                    freeCompartments[2].remainingTickets[2]--;
                    currCompartment = freeCompartments[2].upper;
                } else if (freeCompartments[1] != null) {
                    passenger.ticketDetails = "" + findIndexCompartment(freeCompartments[1]) + "MID";
                    freeCompartments[1].remainingTickets[1]--;
                    currCompartment = freeCompartments[1].middle;
                } else if (freeCompartments[0] != null) {
                    passenger.ticketDetails = "" + findIndexCompartment(freeCompartments[0]) + "LOW";
                    freeCompartments[0].remainingTickets[0]--;
                    currCompartment = freeCompartments[0].lower;
                } else if (freeCompartments[3] != null) {
                    passenger.ticketDetails = "" + findIndexCompartment(freeCompartments[3]) + "RAC";
                    freeCompartments[3].remainingTickets[3]--;
                    currCompartment = freeCompartments[3].rac;
                }
                break;
            default:
                break;
        }
        if (currCompartment != null) {
            for (int i = 0; i < currCompartment.length; i++) {
                if (currCompartment[i] == null) {
                    currCompartment[i] = passenger;
                    passenger.ticketDetails += (i + 1);
                    System.out.println("Booked details");
                    System.out.println(passenger);
                    return;
                }
            }
            return;
        } else {
            if (this.waitList.size() < 1) {
                passenger.ticketDetails = "WL" + this.waitList.size();
                waitList.add(passenger);
                System.out.println("You have been added to the waitlist");
                System.out.println("Booked details");
                System.out.println(passenger);

                return;
            }
            System.out.println("No tickets available");
            return;
        }
    }

}
