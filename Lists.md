### List Uses
* Stacks - a linear list for which all insertions and deletions (and usually all accesses) are made at one end of the list
* Queues - a linear list for which all insertions are made at one end of the list; all deletions (and usually all accesses) are made at the other end
* Deques - a linear list for which all insertions and deletions (and usually all accesses) are made at the ends of the list

### Sequential List Allocation
The simplest way to store a list is keep items in consecutive equally spaced memory locations starting at some base address.

The **advantages** are small storage space, simple to use, potential constant time lookup
The **disadvantages** are only uniform data structures

**Implementing a stack with a sequential list** can be achieved by storing the current size of the stack and a pointer to the top of the stack.

Overflow concerns:

1. Limited memory available (initially set size)
2. Limited memory available (available memory determined by other growing list)

Solutions:

The stack will initially be given either a set size or be allowed to grow towards another variable size list. With a preset size with overflow conditions, you can either prevent the insertion (error) or reallocate the list to another memory location (slower operation). A variable sequence will need to check if the opposing list has been met.

**Implementing a queue with a sequential list** requires a bit more work as the list changes. First, store the front and rear addresses. Size can be calculated by their difference.

Overflow concerns:

1. The rear exceeds memory allocation.
2. The front meets the rear address (empty list)
3. Allocated memory must be small 

Solutions:

The queue will have a fairly limited size. Even with an adequate size the queue will move forward in its address spaces. As the rear address meets the end of the allocated address, it (rear address) can be moved to the front of the allocated spaces. Essentialy the queue will wrap around (assuming there unused address - the queue isn't full). When inserting an element the pointer will need to take this strategy into consideration.