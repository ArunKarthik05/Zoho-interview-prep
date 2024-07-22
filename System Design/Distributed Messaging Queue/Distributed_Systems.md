### Distributed Systems Fundamentals

#### Basics of Distributed Systems

**1. Definition:**
   - A distributed system is a collection of independent computers that appears to its users as a single coherent system. These computers communicate and coordinate their actions by passing messages to one another.

**2. Characteristics:**
   - **Scalability:** The ability to handle growing amounts of work by adding resources (usually hardware).
   - **Fault Tolerance:** The system continues to operate properly in the event of the failure of some of its components.
   - **Concurrency:** Multiple processes can run simultaneously, improving efficiency and performance.
   - **Transparency:** Users and applications should be unaware of the multiple computers in the system, making it appear as a single entity.

**3. Components:**
   - **Nodes:** Individual computers in the distributed system.
   - **Network:** The communication infrastructure connecting the nodes.
   - **Middleware:** Software that provides common services and capabilities to applications outside of what's offered by the operating system.
   - **Protocols:** Rules governing data exchange between nodes.

**4. Examples:**
   - Distributed databases (e.g., Google Spanner, Cassandra)
   - Distributed file systems (e.g., Hadoop HDFS, Google File System)
   - Cloud computing platforms (e.g., AWS, Microsoft Azure)
   - Microservices architectures

#### Concepts of Consistency, Availability, and Partition Tolerance (CAP Theorem)

**1. CAP Theorem:**
   - Also known as Brewer's theorem, it states that in any distributed data store, only two out of the following three guarantees can be achieved simultaneously:
     - **Consistency (C):** Every read receives the most recent write or an error. This means that all nodes see the same data at the same time.
     - **Availability (A):** Every request (read or write) receives a response, without guarantee that it contains the most recent write. This means that the system is always available for reads and writes.
     - **Partition Tolerance (P):** The system continues to operate despite arbitrary partitioning due to network failures. This means that the system can handle network splits and continue to function correctly.

**2. Trade-offs:**
   - **CP (Consistency and Partition Tolerance):** In case of a partition, the system sacrifices availability to ensure consistency. Example: Traditional relational databases (RDBMS).
   - **AP (Availability and Partition Tolerance):** In case of a partition, the system sacrifices consistency to ensure availability. Example: NoSQL databases like Cassandra.
   - **CA (Consistency and Availability):** It’s challenging to achieve in distributed systems because network partitions are inevitable. Generally applicable in non-distributed systems.

**3. Practical Implications:**
   - Most systems choose either CP or AP based on their specific requirements, such as the need for strong consistency or high availability in the face of network failures.

#### Distributed System Models

**1. Architectural Models:**
   - **Client-Server Model:** The server provides services, and the client uses those services. This is the most common model.
   - **Peer-to-Peer Model:** All nodes (peers) have equal responsibilities and capabilities, sharing resources amongst each other. Example: BitTorrent.
   - **Master-Slave Model:** One node (master) controls one or more other nodes (slaves). Example: HDFS, where the NameNode is the master and DataNodes are slaves.
   - **Three-Tier Model:** Typically involves a user interface layer, an application logic layer, and a data storage layer. Example: Web applications.

**2. Communication Models:**
   - **Remote Procedure Call (RPC):** A protocol that one program can use to request a service from a program located on another computer in a network.
   - **Message Passing:** Nodes communicate by sending and receiving messages. This can be synchronous or asynchronous.
   - **Shared Memory:** Multiple nodes share a memory space, which they use for communication by reading and writing data. This is less common due to the complexity of maintaining consistency.

**3. Synchronization Models:**
   - **Synchronous Systems:** Operations are coordinated in time, often using a global clock. All nodes proceed in lock-step.
   - **Asynchronous Systems:** There is no global clock, and nodes proceed at independent rates. This is more realistic for large distributed systems.
   - **Semi-Synchronous Systems:** A compromise where there are bounds on message delivery times and process execution speeds, but they are not tightly synchronized.

**4. Data Distribution Models:**
   - **Replication:** Copies of data are stored on multiple nodes to increase availability and fault tolerance. Ensuring consistency among replicas is a major challenge.
   - **Partitioning:** Data is divided into distinct chunks (shards), each managed by different nodes. This increases scalability and manages load distribution.

**5. Failure Models:**
   - **Crash Failure:** A node stops functioning and does not recover.
   - **Omission Failure:** A node fails to send or receive messages.
   - **Timing Failure:** A node's actions (or responses) do not occur within the expected time frame.
   - **Byzantine Failure:** Nodes may produce arbitrary or malicious responses due to bugs or malicious attacks.
