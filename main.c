#include "functions.h"
#include <stdio.h>
#include <time.h>

//this program will show a single perceptron

static float LEARNING_RATE = 0.1;
static int MIN_CORRECT_GUESSES = 20;


int main() {
    //weights for two inputs nodes and one default
    float weight0;
    float weight1;
    float weight2;

    int node0 = 1;

    //number of sets of nodes
    int numberOfSets;

    printf("\nWELCOME TO PERCEPTRON TRAINING PROGRAM\nHow many sets"
           " of data you would like to provide: ");
    scanf("%d", &numberOfSets);
    int targetOutputs[numberOfSets];
    int node1s[numberOfSets];
    int node2s[numberOfSets];

    //collecting training data from user
    for (int i = 0; i < numberOfSets; i++) {
        printf("\nPlease provide set of data number %d\n", i);
        printf("Node1: ");
        scanf("%d", &node1s[i]);
        printf("Node2: ");
        scanf("%d", &node2s[i]);
        printf("Target output for these nodes: ");
        scanf("%d", &targetOutputs[i]);
    }

    srand(time(NULL));
    //first initializing weights to random float values
    weight0 = (float)rand()/(float)(RAND_MAX/1.0);
    weight1 = (float)rand()/(float)(RAND_MAX/1.0);
    weight2 = (float)rand()/(float)(RAND_MAX/1.0);
    printf("\nInitial weights are:\n%f, %f, %f\n", weight0, weight1, weight2);

    int hasLearned = 0;
    int howManyCorrect = 0;
    int howManyIncorrect = 0;
    int computationOutcome;

    //learning loop
    do {
        for (int i = 0; i < numberOfSets; i++) {
            //check the output of dataset 'i' with current weights
            computationOutcome = perceptronComputation(weight0, weight1, weight2, node1s[i], node2s[i]);
            printf("\n----\nUsing weights: %f, %f, %f, the perceptron output is %d.\n"
                   "Correct answer is %d.", weight0, weight1, weight2, computationOutcome, targetOutputs[i]);
            //if output not correct update weights using perceptron learning rule
            if (computationOutcome != targetOutputs[i]) {
                weight0 = adjustWeights(LEARNING_RATE, weight0, node0, targetOutputs[i], computationOutcome);
                weight1 = adjustWeights(LEARNING_RATE, weight1, node1s[i], targetOutputs[i], computationOutcome);
                weight2 = adjustWeights(LEARNING_RATE, weight2, node2s[i], targetOutputs[i], computationOutcome);

                howManyIncorrect++;
                printf("\nIncorrect guess.");
            } else {
                howManyCorrect++;
                printf("\nCorrect quess.");
            }
            printf("\nCorrectly guessed answers: %d.", howManyCorrect);
            printf("\nIncorrectly guess answers: %d.", howManyIncorrect);
        }
        //if perceptron performed an amount of correct guesses exit the learning loop
        if (howManyCorrect > MIN_CORRECT_GUESSES) {
            hasLearned = 1;
        }
    } while(!hasLearned);

    //menu section for checking what the perceptron will output after learning is done
    int choice;
    int nodeOne, nodeTwo;
    int output;
    int exit = 0;
    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nNode1: ");
                scanf("%d", &nodeOne);
                printf("\nNode2: ");
                scanf("%d", &nodeTwo);
                output = perceptronComputation(weight0, weight1, weight2, nodeOne, nodeTwo);
                printf("\nOutput for %d and %d is %d.", nodeOne, nodeTwo, output);
                break;
            case 2:
                exit = 1;
                break;
            default:
                printf("\nTry again.\n");
                break;
        }

    } while(!exit);

    return 0;
}
