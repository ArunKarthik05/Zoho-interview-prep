import java.util.Arrays;

public class Compartment {
    Passenger [] lower;
    Passenger [] middle;
    Passenger [] upper;
    Passenger [] rac;

    int [] remainingTickets = {21, 21, 21, 18};
    int berthRemaining;
    
    boolean isFull;

    public Compartment(){
        this.lower = new Passenger[21];
        this.middle = new Passenger[21];
        this.upper = new Passenger[21];
        this.rac = new Passenger[18];

        // this.remainingTickets = new int[] ;  // low, mid, upp, rac
        
        this.isFull = false;
        
    }

    @Override
    public String toString() {
        return "Compartment [lower=" + Arrays.toString(lower) + ", middle=" + Arrays.toString(middle) + ", upper="
                + Arrays.toString(upper) + ", rac=" + Arrays.toString(rac) + ", remainingTickets="
                + Arrays.toString(remainingTickets) + ", berthRemaining=" + berthRemaining + ", isFull=" + isFull + "]";
    }
    
}
