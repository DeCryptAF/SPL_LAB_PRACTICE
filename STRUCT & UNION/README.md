## acct->names.firstName  vs  acct.names.firstName

In C, the difference between `acct->names.firstName` and `acct.names.firstName` comes down to how you access the members of a structure based on whether you have a pointer to the structure or the structure itself.

1. **Using a Pointer to a Structure (`acct->names.firstName`):**
   - When you have a pointer to a structure, you use the `->` operator to access its members.
   - The `->` operator is syntactic sugar for dereferencing a pointer and accessing the member of the structure it points to.
   - Example:
     ```c
     struct account *acctPtr;
     acctPtr = &record;
     strcpy(acctPtr->names.firstName, "John");
     ```

2. **Using the Structure Itself (`acct.names.firstName`):**
   - When you have an actual structure (not a pointer to a structure), you use the `.` operator to access its members.
   - The `.` operator directly accesses the member of the structure.
   - Example:
     ```c
     struct account acct;
     strcpy(acct.names.firstName, "John");
     ```
