# Smart Calculator

# About

I started this little project a year or two ago to being learning a little bit about C++.

This year, I decided to bump up the difficulty a bit by moving from typical 1+1 operations to something
a little more complicated.

I wanted to create a project where the calculator would take a mathemtical expression and be able to
parse through it, keeping PEMDAS in mind, and performing the right calculations in order.

I also wanted to add four memory functions to the app so that the app maintained in memory the number
that the user wanted to add to or subtract from.

Another neat feature I thought of was to add a history of the operations used in the console app so that the user could easily go back and see the calculations that they performed.

# Learnings

The memory functions and history were pretty simple and straight forward, but man parsing through the expression
was a little more convoluted than I thought.

At first, I wanted to try a few brute force attempts to parse through the expressions but the code was just meh, so I looked up if there was any algorithms that was used to solve this sort of problem.

## Algorithm

I discovered something called [Reverse Polish Notation (RPN)](https://en.wikipedia.org/wiki/Reverse_Polish_notation). RPN is basically a method for doing math by having the operators at the end of the
operands (the numbers you're operating). So, for example, instead of 2 + 3 (this is our normal approach), in RPN
you would do 2 3 +.

The way it works is that you use a stack data structure to stack the numbers that you're going to operate on and store the operations in a dynamic list/array (e.g., C++'s vector). You control the order by using PEMDAS and storing/pushing the operations in numbers. This way, once we evaluate the RPN expressions, we do so in an ordered way that respects the original expression. It's really really neat and simplifies the operations.

This was a fun little project to work on!