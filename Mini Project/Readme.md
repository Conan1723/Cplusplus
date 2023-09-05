1) I provided a database file that contains many student records. The entries are: student ID, major, grade (percentage), admission type (4-year, ASI, ASII), and admission year. Your program should ask the user to input the file name rather than hardcoding it. We will use two different input files (with the same format) to test the system. You can assume that the database file is correct without containing bad formatted student records or duplicated items (same ID). 

2) Create an indexing structure for this database using binary search tree. Note that you cannot use any tree-related classes from STL. You should define the struct of the node and implement it from scratch (need left and right pointers). 

3) Ask users to input one of four operations once you finish creating the index.
   1. search
   2. insert
   3. delete
   4. over

If the user inputs anything else (e.g. some random strings), output: “You must choose one of the four operations: search, insert, delete, over”. 

If the user inputs "search", ask: "What is the student ID", read the ID and output either the student's record or "This ID does not exist". If the user inputs an ID that is not 8 digits, you can directly return “This ID does not exist” instead of searching it in the tree. 

If the user inputs "insert", ask: "What is the record", read the whole line and check whether it has the same format as the input file. If yes, add it to the BST, otherwise output "wrong format". If the user inputs a record that contains the same ID as one of your current entries, you should warn the user: “This ID is already used. Invalid input!”. 

If the user inputs "delete", ask: "What is the ID you want to delete", read the ID and then just do the soft deletion. Simply change the major as "null". If the ID does not exist, you should output: “wrong ID, nothing to delete!”. 

If the user inputs “over”, exist the system (i.e. the program). 

