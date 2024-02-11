#include <stdio.h>

#define MAX_WEIGHT 20
#define MAX_ITEMS 5

// A utility function that returns maximum of two integers
int max(int a, int b) {
    return a > b ? a : b;
}

// Function to fill the selected_bool array after solving the knapsack problem
void fillSelectedBool(int weights[], int selected_bool[], int n, int W, int K[][W+1])
{
    for (int i = n; i >=  0 && W >  0; i--)
        if (K[i][W] != K[i-1][W])
        {
            selected_bool[i-1] =  1; // Item is included
            W -= weights[i-1]; // Reduce the remaining capacity
        }
}

// Modified knapSack function that fills the selected_bool array
int knapSack(int weights[], int values[], int *selected_bool) {
    int W =  MAX_WEIGHT; // Bag capacity
    int n = MAX_ITEMS;
    int K[n+1][W+1];

    // Build table K[][] in bottom up manner
    for (int i =  0; i <= n; i++)
        for (int w =  0; w <= W; w++)
            if (i ==  0 || w ==  0)
                K[i][w] =  0;
            else if (weights[i-1] <= w)
                K[i][w] = max(values[i-1] + K[i-1][w-weights[i-1]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];

    // Fill the selected_bool array
    fillSelectedBool(weights, selected_bool, n, W, K);

    return K[n][W]; // Return the maximum value that can be put in the knapsack
}

int main(int argc, char* argv[])
{
    int weights[MAX_ITEMS] = {0};
    int values[MAX_ITEMS] = {0};
    char items[MAX_ITEMS][MAX_WEIGHT + 1] = {0};
    int selected_bool[MAX_ITEMS] = {0};
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        scanf("%s", items[i]);
        scanf("%d", &values[i]);
        scanf("%d", &weights[i]);
    }

    printf("Maximum profit: %d\n", knapSack(weights, values, selected_bool));

    // Print the selected items
    printf("Selected items:");
    for (int i =  0; i < MAX_ITEMS; i++)
        if (selected_bool[i] ==  1)
            printf(" %s", items[i]);

    return  0;
}