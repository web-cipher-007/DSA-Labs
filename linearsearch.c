#include <stdio.h>
void LinearSearch(int A[], int n, int key) {
    int Flag = 0;  
    
    for (int i = 0; i < n; i++) {
        if (A[i] == key) {
            printf("Search successful\n");
            Flag = 1;  
            break;    
        }
    }
    
    if (Flag == 0) {
        printf("Search unsuccessful\n");
    }
}

int main() {
    int A[] = {69, 23, 78, 97, 51};
    int n = sizeof(A) / sizeof(A[0]);
    int key = 97;

    LinearSearch(A, n, key);

    return 0;
}
