# push_swap
Push_swap is 42 or WeThinkCode_ that sorts a given list of numbers using two stacks (Stack A and Stack B) as containers. The program uses a list of predetermined commands to try and sort the stack.

The commands are as follows:
----------------------------
ra = rotate stack A, takes the number at the top of the stack A and makes it the last one.
rra = reverse rotate stack A, takes the last number on the stack A and makes it the first one.
sa = swap A, swaps the first two elements on stack A.
pa = push A, pops an element from stack B if there's one and pushes it to stack A.
rb = rotate stack B, takes first element on stack B and makes it the last one.
rrb = reverse rotate stack B, takes the last element on stack B and makes it the first one.
sb = swap B, swaps the first two elements of stack B.
rr = performs ra and rb at the same time.
rrr = performs rra and rrb at the same time.
ss = performs sa and sb at the same time.

push_swap and checker program:
------------------------------
1. The push_swap program takes a list of integer numbers without duplicates as command line arguments.
It then tries to sort them and the displays the list of commands it used to sort the list.
2. The checker program takes a list of integer numbers without duplicates as command line arguments.
It then wait for you to give it commands to sort the list. You can only right one command in each line with out spaces the press enter.
Once you are done entering the command you must press cntrl + del. The program will the display "OK" or "KO" depending on whether the 
stack is sorted on not.

Running the program.
--------------------
clone the repository and run make.
This should generate two executable named push_swap and checker.
You can the give the a list of integer values and command line args.

NOTE:
My push_swap program currently can works best for up to 12 numbers.
