### Message Queue Architecture
![image](https://github.com/user-attachments/assets/39f18b63-5e89-46fd-b595-cb674b9604e4)


#### Producer-Consumer Model

The producer-consumer model is a fundamental pattern in distributed messaging systems where producers create messages and consumers process them. The messages are typically stored in a queue managed by a message broker. Here's a detailed explanation:

**1. Producers:**
   - Producers are applications or components that create messages and send them to the message queue.
   - Producers do not need to know the details about the consumers or how many consumers are there.

**2. Consumers:**
   - Consumers are applications or components that retrieve and process messages from the queue.
   - Consumers can work independently and concurrently, which allows for scalable processing.

#### Message Brokers

Message brokers are intermediaries that facilitate communication between producers and consumers. They handle the storage, routing, and delivery of messages. Common message brokers include RabbitMQ, Apache Kafka, and AWS SQS.

**Functions of a Message Broker:**
- **Message Storage:** Temporarily stores messages until they can be processed by consumers.
- **Message Routing:** Directs messages to the appropriate queue based on routing rules.
- **Load Balancing:** Distributes messages evenly across multiple consumers.
- **Persistence:** Ensures messages are not lost in case of failures.
- **Scalability:** Can handle a high volume of messages by distributing the load across multiple brokers or nodes.

#### Message Delivery Semantics

Message delivery semantics define how a message is delivered and acknowledged between producers, brokers, and consumers. The three primary delivery semantics are:

**1. At Most Once:**
   - Messages are delivered once, but may be lost if there is a failure.
   - Suitable for applications where occasional message loss is acceptable.

**2. At Least Once:**
   - Messages are delivered one or more times, ensuring delivery but possibly resulting in duplicates.
   - Suitable for applications where message loss is unacceptable, but duplicates can be handled.

**3. Exactly Once:**
   - Messages are delivered once and only once, ensuring no loss and no duplicates.
   - Suitable for applications where both message loss and duplicates are unacceptable.
   - This is the most complex and resource-intensive to implement.

#### Message Acknowledgement

Message acknowledgment is the process by which a consumer notifies the broker that a message has been successfully processed. This ensures that messages are not lost or reprocessed unnecessarily.

**Acknowledgment Process:**
- **Consumer Acknowledgment:** After processing a message, the consumer sends an acknowledgment to the broker.
- **Broker Actions:** 
  - If the acknowledgment is received, the broker removes the message from the queue.
  - If the acknowledgment is not received (due to a consumer failure), the broker can redeliver the message to another consumer.
