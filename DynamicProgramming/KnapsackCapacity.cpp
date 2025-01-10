// here is the implementation on how to solve the knapsack problem

#include<iostream>
using namespace std;

//recursiv function to solve the knapsack problem
int knapsack(int weights[], int value[], int n , int capacity) {
    //base case
    if(n == 0 || capacity == 0) {
        return 0;
    }

    //if the nth item's weight is > the capacity, skip it 
    if(weights[n-1] > capacity) {
        return knapsack(weights, value, n - 1, capacity);  
    } 

    //otherwise return one of the two cases:
    //1. to include the item
    //2. to exclude the item

    int includeItem = values[n - 1] + knapsack(weights, values, n - 1, capacity - weights[n - 1]);
    int excludeItem = knapsack(weights, values, n - 1, capacity);
    return max(includeItem, excludeItem);
}

