### Apache Kafka

Apache Kafka is a distributed streaming platform used for building real-time data pipelines and streaming applications. It is designed to handle large volumes of data with high throughput and low latency.

#### Architecture

**1. Key Components:**
   - **Producers:** Applications that send data to Kafka topics.
   - **Consumers:** Applications that read data from Kafka topics.
   - **Brokers:** Servers that store data and serve clients (producers and consumers).
   - **Topics:** Categories to which messages are sent by producers and from which messages are read by consumers.
   - **Partitions:** Subdivisions of topics that help distribute data and load across multiple brokers.
   - **ZooKeeper:** A distributed coordination service used by Kafka for managing broker metadata and cluster configuration.

**Architecture Diagram:**

![image](https://github.com/user-attachments/assets/d2874f0f-7b4c-459e-bfdd-8ebcbbe3cd57)

#### Producers, Consumers, and Brokers

**1. Producers:**
   - Producers are applications that publish (send) data to Kafka topics.
   - Producers can send data to specific partitions within a topic based on a partitioning key or in a round-robin fashion.
   - Producers are responsible for choosing the appropriate partition for each message, often based on a key to ensure related messages go to the same partition.

**2. Consumers:**
   - Consumers are applications that subscribe to (read) data from Kafka topics.
   - Consumers can read from multiple partitions of a topic, which allows for parallel processing of messages.
   - Consumer groups are used to distribute the workload among multiple consumers, ensuring that each partition is consumed by only one consumer within a group.

**3. Brokers:**
   - Brokers are Kafka servers that store data and serve requests from producers and consumers.
   - Each broker manages a portion of the partitions for various topics.
   - Brokers communicate with ZooKeeper to maintain cluster state and handle failover.

#### Partitions and Replication

**1. Partitions:**
   - Partitions are the basic unit of parallelism and scalability in Kafka.
   - Each topic is divided into one or more partitions.
   - Partitions allow Kafka to scale horizontally by distributing data across multiple brokers.
   - Each partition is an ordered, immutable sequence of records that is continually appended to.

**2. Replication:**
   - Replication provides fault tolerance by duplicating data across multiple brokers.
   - Each partition has one leader and multiple followers.
   - The leader handles all read and write requests for the partition, while followers replicate the data.
   - If the leader fails, one of the followers is promoted to leader, ensuring high availability.


#### Kafka Streams and Connect

**1. Kafka Streams:**
   - Kafka Streams is a client library for building applications and microservices that process and transform data in Kafka.
   - It allows for real-time stream processing using a simple and declarative API.
   - Kafka Streams applications are elastic, scalable, and fault-tolerant, running on the Kafka cluster.
   - Core concepts include:
     - **Streams:** An unbounded, continuously updating dataset.
     - **Tables:** A stateful representation of a stream, allowing for stateful processing.
     - **KStream and KTable:** Core abstractions for stream and table processing.

**2. Kafka Connect:**
   - Kafka Connect is a framework for connecting Kafka with external systems such as databases, key-value stores, search indexes, and file systems.
   - It provides scalable and reliable data import and export capabilities.
   - Connectors (source and sink) are used to capture data from external systems and push it into Kafka (source) or pull data from Kafka and push it into external systems (sink).
   - Kafka Connect includes:
     - **Standalone Mode:** For simple, single-node setups.
     - **Distributed Mode:** For fault-tolerant and scalable deployments.
