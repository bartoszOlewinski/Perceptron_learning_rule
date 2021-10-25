#include "math.h"
#include "stdlib.h"
#include "stdio.h"

int perceptronComputation(float weight0, float weight1, float weight2,
                          int node1, int node2) {

    if ((weight0 + ((weight1 * (float)node1) + (weight2 * (float)node2))) > 0) {
        return 1;
    } else {
        return -1;
    }
}

float adjustWeights(float learning_rate, float weight, int inputNode,
                   int expectedOutcome, int actualOutcome) {
    weight += learning_rate * (float)(expectedOutcome - actualOutcome) * (float) inputNode;
    return weight;
}

void printMenu() {
    printf("\n---\n1. input values to determine AND.\n2. exit loop.\n");
}