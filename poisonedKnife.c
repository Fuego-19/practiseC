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

int min(int a, int b){
    if(a < b){
        return a;
    }
    else{
        return b;
    }
}

int main(void) {
    int t;
    scanf("%d\n",&t);
    
    while(t-- > 0){
        int n;
        long long h;
        scanf("%d %ld\n", &n, &h);
        
        int times[n];

        for(int i =0; i<n; i++)
        {
            scanf("%d", &times[i]);
        }
        getchar();

        if(n == 1){
            printf("%d", h);
            continue;
        }
        mergeSort(times,0, n - 1);
        // printA(times, n );
        // printf("\n");
        int timeDiff[n - 1];
        for(int i =0; i<n - 1; i++){
            timeDiff[i] = times[i+1] - times[i];
        }
        // printA(timeDiff, n - 1);
        // printf("\n");

        int max = -1;
        int diffSum = 0;
        for(int k =0; k<n - 1; k++){
            if(timeDiff[k] > max){
                max = timeDiff[k];
            }
            diffSum += timeDiff[k];
        }

        int attack = 0;
        int finalAns = 0;
        int flag = 1;
        for(int st =1; st<=max; st++){
            attack = st;
            for(int j = 0; j < n - 1; j++ ){
                attack += min(st, timeDiff[j]);
            }
            if(attack >= h){
                finalAns = st;
                flag = 0;
                break;
            }
        }

        if(flag){
            finalAns = h - diffSum;
        }

        printf("%d\n", finalAns);
        
        
    }

    void printA(int *arr, int n){
        for(int i =0; i<n; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }


}

