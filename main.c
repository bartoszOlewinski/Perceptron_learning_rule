#include "functions.h"
#include <stdio.h>
#include <time.h>

//this program will show a single perceptron

static float LEARNING_RATE = 0.1;


int main() {
    //weights for two inputs nodes
    float weight0;
    float weight1;
    float weight2;

    //number of sets of nodes
    int numberOfSets;

    printf("\nWELCOME TO PERCEPTRON TRAINING PROGRAM\nHow many sets"
           "of data you would like to provide to learn AND? ");
    scanf("%d", &numberOfSets);
    int targetOutputs[numberOfSets];
    int node1s[numberOfSets];
    int node2s[numberOfSets];

    //collecting training data from user
    for (int i = 0; i < numberOfSets; i++) {
        printf("\nPlease provide set of data number %d in format"
               " node return, node return, output return\n", i);
        scanf("%d ", &node1s[i]);
        scanf("%d ", &node2s[i]);
        scanf("%d", &targetOutputs[i]);
    }

    time_t t;
    srand((unsigned) time(&t));
    //first initializing weights to random float values
    weight0 = (float)rand()/(float)(RAND_MAX/1.0);
    weight1 = (float)rand()/(float)(RAND_MAX/1.0);
    weight2 = (float)rand()/(float)(RAND_MAX/1.0);
    printf("\nInitial weights are:\n%f, %f\n", weight1, weight2);

    int hasLearned = 0;
    int computationOutcome;

    //learning llop
    do {
        for (int i = 0; i < numberOfSets; i++) {
            //check if the weights are correct
            computationOutcome = perceptronComputation(weight0, weight1, weight2, node1s[i], node2s[i]);
            printf("\nUsing weights: %f, %f, %f, the perceptron output is %d.\n", weight0, weight1, weight2, computationOutcome);
            //if not we need to adjust them
            if (computationOutcome == -1) {
                adjustWeights(LEARNING_RATE, &weight1, node1s[i], targetOutputs[i], computationOutcome);
                adjustWeights(LEARNING_RATE, &weight2, node2s[i], targetOutputs[i], computationOutcome);
            } else {
                hasLearned = 1;
                break;
            }
        }
    } while(!hasLearned);





    return 0;
}
