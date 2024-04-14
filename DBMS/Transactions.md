## Transactions in Databases

In the context of databases, a transaction is a logical unit of work that consists of one or more database operations (such as inserts, updates, or deletes). These operations are grouped together as a single unit, and either all of them are executed successfully or none of them are executed at all. This concept is known as the ACID properties:

1. **Atomicity**: A transaction is atomic, meaning it either completes successfully and commits all changes to the database, or it fails and leaves the database unchanged. There is no partial execution of a transaction.

2. **Consistency**: A transaction preserves the consistency of the database by ensuring that the database moves from one consistent state to another consistent state. In other words, the database constraints are enforced at the end of each transaction.

3. **Isolation**: Transactions are isolated from each other, meaning that the intermediate state of one transaction is not visible to other transactions until it is committed. This ensures that transactions execute as if they were the only transactions running on the database.

4. **Durability**: Once a transaction is committed, the changes made by the transaction are permanently saved in the database and are not lost even in the event of a system failure.

### Example of a Transaction

```sql
BEGIN TRANSACTION;

UPDATE accounts SET balance = balance - 100 WHERE account_id = 123;
INSERT INTO transactions (account_id, amount, type) VALUES (123, -100, 'Withdrawal');

COMMIT;
```

## Interviewer Question
Interviewer: Imagine you're developing a banking application where users can transfer money between their accounts. How would you ensure that these transfers are performed atomically to maintain data consistency and integrity?

- Answer to the Interviewer Question:

- To ensure that money transfers between accounts are performed atomically, I would encapsulate the transfer operation within a transaction. Within this transaction, I would first deduct the amount from the sender's account and then add the same amount to the recipient's account. If either of these operations fails (due to insufficient funds, for example), the entire transaction would be rolled back to its original state, ensuring that the database remains consistent. Additionally, I would use appropriate locking mechanisms to prevent concurrent access to the same accounts during the transfer process, thereby maintaining data integrity.