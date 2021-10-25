#include "functions.c"

int perceptronComputation(float weight0, float weight1, float weight2,
                          int node1, int node2);

float adjustWeights(float learning_rate, float weight, int inputNode,
                   int expectedOutcome, int actualOutcome);