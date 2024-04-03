public class Passenger {
    String name;
    int age;
    char gender;
    char berthPreference;
    boolean withChildren;
    Passenger child;
    String ticketDetails;

    public Passenger(String name, int age, char gender, char berthPreference) {
        this.name = name;
        this.age = age;
        this.gender = gender;
        this.berthPreference = berthPreference;
        this.withChildren = false;
        this.child = null;
        this.ticketDetails = "NA";
    }

    public Passenger(String name, int age, char gender, char berthPreference, boolean withChildren, Passenger child) {
        this.name = name;
        this.age = age;
        this.gender = gender;
        this.berthPreference = berthPreference;
        this.withChildren = withChildren;
        this.child = child;
        this.ticketDetails = "NA";
    }

    public Passenger(String name, int age, char gender) {
        this.name = name;
        this.age = age;
        this.gender = gender;
        this.berthPreference = '\0';
        this.withChildren = false;
        this.child = null;
        this.ticketDetails = "NA";
    }

    @Override
    public String toString() {
        return "Passenger [name=" + name + ", age=" + age + ", gender=" + gender + ", berthPreference="
                + berthPreference + ", withChildren=" + withChildren + ", child=" + child + ", ticketDetails="
                + ticketDetails + "]";
    }
}
