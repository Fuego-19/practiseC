#include <stdio.h>
void printA(int *arr, int n){
    for(int i =0; i<n; i++){
        printf("%d ", arr[i]);
    }
}

void merge(int *arr, int s, int m, int e) {
    int n1 = m - s + 1;
    int n2 = e - m;
    int tempL[n1], tempR[n2];
    for (int i = 0; i < n1; i++) {
        tempL[i] = arr[s + i];
    }
    for (int j = 0; j < n2; j++) {
        tempR[j] = arr[m + 1 + j];
        
    }
    int i = 0, j = 0, k = s;
    while (i < n1 && j < n2) {
        if (tempL[i] <= tempR[j]) {
           
            arr[k++] = tempL[i++];
        }
        else {
           
            arr[k++] = tempR[j++];
        }
    }
    while (i < n1) {
        
        arr[k++] = tempL[i++];
    }
    while (j < n2) {
       
        arr[k++] = tempR[j++];
    }
}
 
void mergeSort(int *arr, int s, int e) {
    if (s >= e)
        return;
    int m = s + (e - s)/2;
    mergeSort(arr, s, m);
    mergeSort(arr, m + 1, e);
    merge(arr, s, m, e);
}

int main(void) {
    int t;
    scanf("%d\n",&t);
    
    while(t-- > 0){
        int n,h;
        scanf("%d %d\n", &n, &h);
        
        int times[n];

        for(int i =0; i<n; i++)
        {
            scanf("%d", &times[i]);
        }
        getchar();
        printA(times, n);

        
    }

    void printA(int *arr, int n){
        for(int i =0; i<n; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

