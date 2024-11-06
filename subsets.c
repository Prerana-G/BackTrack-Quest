#include <stdio.h>

#define MAX_SIZE 100  //Maximum size for the set

void print_subset(int subset[], int size) {
    int i;
    printf("{ ");
    for (i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}

void subsets(int set[], int n, int subset[], int subset_size, int index, int current_sum, int d, int *found) {
    if (current_sum == d) {
        print_subset(subset, subset_size);
        *found = 1;
        return;
    }
    if (index >= n || current_sum > d) {
        return;
    }

    // Include the current element
    subset[subset_size] = set[index];
    subsets(set, n, subset, subset_size + 1, index + 1, current_sum + set[index], d, found);

    // Exclude the current element
    subsets(set, n, subset, subset_size, index + 1, current_sum, d, found);
}

int main() {
    int set[MAX_SIZE];
    int subset[MAX_SIZE];
    int n, d, i;
    int found = 0;  // Flag to check if a subset is found

    printf("Enter the number of elements in the set (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("Number of elements exceeds maximum size of %d.\n", MAX_SIZE);
        return 1;
    }
    printf("Enter the elements of the set:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &d);
    subsets(set, n, subset, 0, 0, 0, d, &found);

    if (!found) {
        printf("No subset possible!\n");
    }
    return 0;
}


