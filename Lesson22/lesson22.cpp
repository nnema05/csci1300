/*  WHEN READING FILES!
Are all rows the same? Does the file have a header row?
How is the data formatted and what do you need to do with it?
Bob, 3
Bob 3
Bob: 3
Extra characters, spaces, newline at the end of a line 

// data has a header, treat it differently then every other row
Name, score
Bob, 10

// data has a header and every other row is different, name on one row, score on second row
Name, score
Bob
10 
Sally 
20 

unknown number of columns, read an arbitrary number of columns
Bob 3, 30, 23, 24
Sally 4, 23, 1

how do we fine the , the space, the new line and use it as a splitter 
*/

