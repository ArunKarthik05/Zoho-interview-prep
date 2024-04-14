# Multiple Granularity Locking (MGL)

Multiple granularity locking (MGL) is a concurrency control technique used in database management systems (DBMS) to improve concurrency and reduce contention by allowing transactions to acquire locks at different levels of granularity. This approach enables transactions to lock only the specific resources they need, rather than locking entire tables or databases, thereby reducing the likelihood of deadlocks and improving system throughput. Here's how it works:

## Granularity Levels:
MGL supports multiple levels of granularity for locking. These levels typically include:
- **Database Level**: Locking at the database level involves acquiring locks on the entire database. This is the coarsest granularity level and provides maximum isolation but may lead to excessive contention and reduced concurrency.
- **Table Level**: Locking at the table level involves acquiring locks on entire database tables. This granularity level offers a balance between isolation and concurrency but may still result in contention if multiple transactions access the same table simultaneously.
- **Page Level**: Locking at the page level involves acquiring locks on individual data pages within a table. This granularity level reduces contention further by allowing transactions to lock only the specific pages they need, but it may still be too coarse for highly concurrent systems.
- **Row Level**: Locking at the row level involves acquiring locks on individual rows within a table. This is the finest granularity level and provides maximum concurrency but may incur additional overhead due to the increased number of locks.

## Lock Compatibility:
MGL allows different transactions to acquire locks at different levels of granularity simultaneously while ensuring compatibility between locks to prevent conflicts. For example, a transaction holding a row-level lock on a particular row should not block another transaction from acquiring a table-level lock on the same table.

## Lock Promotion and Demotion:
MGL supports lock promotion and demotion, allowing transactions to escalate or de-escalate their lock granularity dynamically based on their access patterns and resource requirements. For example, a transaction initially acquiring row-level locks may escalate to acquire a table-level lock if it needs to access a significant portion of the table.

## Reduced Contention:
By allowing transactions to acquire locks at different levels of granularity, MGL reduces contention for resources and improves concurrency. Transactions can lock only the specific resources they need, minimizing the likelihood of conflicts and deadlocks compared to traditional coarse-grained locking approaches.

## Increased Flexibility:
MGL provides increased flexibility for applications with diverse access patterns and requirements. Transactions can choose the appropriate granularity level for locking based on factors such as data access patterns, transaction size, and performance considerations.

Overall, multiple granularity locking is a powerful concurrency control technique that strikes a balance between isolation and concurrency by allowing transactions to acquire locks at different levels of granularity, thereby improving system performance and scalability in database environments.
