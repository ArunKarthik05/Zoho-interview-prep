TCP, or Transmission Control Protocol, is one of the core protocols of the Internet Protocol Suite (TCP/IP). It operates at the transport layer (Layer 4) of the TCP/IP model and is responsible for establishing and maintaining a reliable connection between two devices over a network. Here's a breakdown of its key features:

1. **Reliability**: TCP ensures reliable delivery of data by using mechanisms such as acknowledgments, sequence numbers, and retransmission of lost packets. When data is transmitted, TCP assigns a sequence number to each segment. The receiving device acknowledges the receipt of each segment, and if any segment is lost or damaged, TCP retransmits it until it's successfully delivered.

2. **Connection-oriented**: TCP establishes a connection before data transfer begins and ensures that data is delivered in the correct order. This connection-oriented nature of TCP involves a three-way handshake process between the sender and receiver to establish the connection, followed by data transfer, and finally, a connection termination phase.

3. **Flow Control**: TCP implements flow control mechanisms to prevent a fast sender from overwhelming a slow receiver. It uses a sliding window mechanism where the sender adjusts the rate of data transmission based on feedback from the receiver about its buffer capacity.

4. **Congestion Control**: TCP monitors network congestion and adjusts its transmission rate accordingly to avoid network congestion and ensure fair sharing of network resources among competing connections.

5. **Full-duplex communication**: TCP supports full-duplex communication, allowing data to be transmitted in both directions simultaneously.

Overall, TCP provides a reliable, connection-oriented, and error-checked delivery of data over IP networks, making it suitable for applications that require guaranteed delivery and sequencing of data, such as web browsing, email, file transfer, and remote access.

**Interview Question:**
Imagine you're tasked with troubleshooting a network performance issue where users are experiencing slow download speeds when accessing a file server over the LAN. After conducting initial tests, you suspect that TCP congestion control might be causing the problem. How would you verify whether TCP congestion control is indeed the issue, and what steps would you take to mitigate it?