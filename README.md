# Simple-Perceptron
Simple C program that uses perceptron learning rule as explained in Machine Learning by Tom M. Mitchell,
to learn simple boolean functions such as AND, OR, NAND or NOR.

It works with 1 (true) and -1 (false) as input for dataset (input nodes and target output).

Runs on C99, compiled using gcc.


----EDIT----
This perceptron training rule can run with 1 (true) and 0 (false) if in perceptronComputation function second
return statement's value is changed from -1 to 0, and if node0 in main() is changed to -1.
