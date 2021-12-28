Memory Manager task
1. Implement a memory manager in the form of a program module.
It allows you to receive blocks of memory of various sizes, free them.
The memory manager contains a large byte array and its division into disjoint blocks.
The allocation function of the new block gets the size and returns some non-negative integer -
handle to the new block. There cannot be two different blocks simultaneously existing with the same descriptor.
The delete function gets this block descriptor.
The memory byte read function gets the block descriptor and offset from the start of the block and returns
the byte value at this offset.

The memory byte write function gets the same parameters and the value that needs to be written to the memory byte.
The manager must control the correctness of memory accesses: when there is going out of block boundaries or
specifying a non-existent block, diagnostics should be printed and the program should be terminated (by calling the function exit).
2. Write one more program module that extends the module from item 1 with the block reallocation function.
The function receives a block descriptor and a new size as input. The function returns 0 on success and non-zero
number on failure. The function does not change the block descriptor.
3. Using the module from item 2, solve the problem: print the longest input line.
