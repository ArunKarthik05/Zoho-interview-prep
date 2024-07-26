### CQRS (Command Query Responsibility Segregation) Architecture
CQRS is an architectural pattern that separates the reading (query) and writing (command) of data into two different models. This separation allows for optimized performance, scalability, and security by handling read and write operations differently.

![image](https://github.com/user-attachments/assets/8327310a-120f-407e-b268-69c476a90f85)

### Key Components

1. **Command Model (Write Model)**:
   - Handles the creation, updating, and deletion of data.
   - Typically uses a relational database to maintain strong consistency.
   - Commands are responsible for changing the state of the system.

2. **Query Model (Read Model)**:
   - Handles data retrieval operations.
   - Can use optimized databases like NoSQL, in-memory databases, or search engines for fast querying.
   - Queries do not change the system's state; they only retrieve data.

3. **Event Sourcing**:
   - Events represent state changes that have occurred in the system.
   - The write model stores these events, which can be replayed to reconstruct the state.

### Communication Between Command and Query Models

1. **Event Bus**:
   - Commands result in events that are published to an event bus.
   - The event bus distributes these events to interested subscribers, including the read model.

2. **Projections**:
   - The read model subscribes to events from the event bus.
   - It updates its own database to reflect the current state based on the received events.

### Example Scenario: E-commerce Order Processing

**Components**:
- **Command Service**: Manages order creation and updates.
- **Query Service**: Handles order status and details retrieval.
- **Event Bus**: Facilitates communication between the command and query services.

### Step-by-Step Process

1. **Order Creation (Command Model)**:
   - A customer places an order via the Order Service (Command Service).
   - The Order Service validates the order and stores it in the command database.
   - The Order Service generates an `OrderCreated` event and publishes it to the event bus.

2. **Event Bus**:
   - The event bus receives the `OrderCreated` event and forwards it to all subscribed services, including the Query Service.

3. **Order Update (Query Model)**:
   - The Query Service listens for `OrderCreated` events on the event bus.
   - Upon receiving the event, the Query Service updates its own read-optimized database to include the new order details.
   - Now, the order details are available for querying by customers or other systems.

4. **Order Status Query (Query Model)**:
   - A customer queries the Order Service (Query Service) for the status of their order.
   - The Query Service retrieves the order details from the read database and returns the response.
