#include <stdio.h>

// Function to print a set
void printSet(int set[], int size) {
    printf("{");
    for (int i = 0; i < size; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("%d", set[i]);
    }
    printf("}\n");
}

// Function to find the union of two sets
void unionSets(int A[], int sizeA, int B[], int sizeB) {
    int result[sizeA + sizeB];
    int resultSize = 0;

    // Add elements of A to result
    for (int i = 0; i < sizeA; i++) {
        result[resultSize++] = A[i];
    }

    // Add elements of B to result if not already present
    for (int i = 0; i < sizeB; i++) {
        int found = 0;
        for (int j = 0; j < sizeA; j++) {
            if (B[i] == A[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            result[resultSize++] = B[i];
        }
    }

    printf("Union of A and B: ");
    printSet(result, resultSize);
}

// Function to find the intersection of two sets
void intersectionSets(int A[], int sizeA, int B[], int sizeB) {
    int result[sizeA < sizeB ? sizeA : sizeB];
    int resultSize = 0;

    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < sizeB; j++) {
            if (A[i] == B[j]) {
                int alreadyInResult = 0;
                for (int k = 0; k < resultSize; k++) {
                    if (result[k] == A[i]) {
                        alreadyInResult = 1;
                        break;
                    }
                }
                if (!alreadyInResult) {
                    result[resultSize++] = A[i];
                }
                break;
            }
        }
    }

    printf("Intersection of A and B: ");
    printSet(result, resultSize);
}

// Function to find the set difference A \ B and B \ A
void setDifference(int A[], int sizeA, int B[], int sizeB) {
    int diffA[sizeA];
    int diffB[sizeB];
    int diffASize = 0;
    int diffBSize = 0;

    // A \ B
    for (int i = 0; i < sizeA; i++) {
        int found = 0;
        for (int j = 0; j < sizeB; j++) {
            if (A[i] == B[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            diffA[diffASize++] = A[i];
        }
    }

    // B \ A
    for (int i = 0; i < sizeB; i++) {
        int found = 0;
        for (int j = 0; j < sizeA; j++) {
            if (B[i] == A[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            diffB[diffBSize++] = B[i];
        }
    }

    printf("A \\ B: ");
    printSet(diffA, diffASize);
    printf("B \\ A: ");
    printSet(diffB, diffBSize);
}

// Function to find the symmetric difference of two sets
void symmetricDifference(int A[], int sizeA, int B[], int sizeB) {
    int unionAB[sizeA + sizeB];
    int intersectionAB[sizeA < sizeB ? sizeA : sizeB];
    int unionSize = 0;
    int intersectSize = 0;

    // Union
    for (int i = 0; i < sizeA; i++) {
        unionAB[unionSize++] = A[i];
    }
    for (int i = 0; i < sizeB; i++) {
        int found = 0;
        for (int j = 0; j < sizeA; j++) {
            if (B[i] == A[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            unionAB[unionSize++] = B[i];
        }
    }

    // Intersection
    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < sizeB; j++) {
            if (A[i] == B[j]) {
                int alreadyInIntersect = 0;
                for (int k = 0; k < intersectSize; k++) {
                    if (intersectionAB[k] == A[i]) {
                        alreadyInIntersect = 1;
                        break;
                    }
                }
                if (!alreadyInIntersect) {
                    intersectionAB[intersectSize++] = A[i];
                }
                break;
            }
        }
    }

    // Symmetric Difference = Union - Intersection
    int symmetricDiff[unionSize];
    int symDiffSize = 0;

    for (int i = 0; i < unionSize; i++) {
        int found = 0;
        for (int j = 0; j < intersectSize; j++) {
            if (unionAB[i] == intersectionAB[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            symmetricDiff[symDiffSize++] = unionAB[i];
        }
    }

    printf("Symmetric Difference A and B: ");
    printSet(symmetricDiff, symDiffSize);
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    int B[] = {4, 5, 6, 7, 8};
    int sizeA = sizeof(A) / sizeof(A[0]);
    int sizeB = sizeof(B) / sizeof(B[0]);

    unionSets(A, sizeA, B, sizeB);
    intersectionSets(A, sizeA, B, sizeB);
    setDifference(A, sizeA, B, sizeB);
    symmetricDifference(A, sizeA, B, sizeB);

    return 0;
}
