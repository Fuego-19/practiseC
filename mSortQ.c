 #include <stdio.h>
void merge(int *arr, int *follower, int s, int m, int e) {
    int n1 = m - s + 1;
    int n2 = e - m;
    int tempL[n1], tempR[n2];
    int tempfol[n1], tempfol2[n2];
    for (int i = 0; i < n1; i++) {
        tempL[i] = arr[s + i];
        tempfol[i] = follower[s + i];
    }
    for (int j = 0; j < n2; j++) {
        tempR[j] = arr[m + 1 + j];
        tempfol2[j] = follower[m + 1 + j];
        
    }
    int i = 0, j = 0, k = s;
    while (i < n1 && j < n2) {
        if (tempL[i] <= tempR[j]) {
            follower[k] = tempfol[i];
            arr[k++] = tempL[i++];
        }
        else {
            follower[k] = tempfol2[j];
            arr[k++] = tempR[j++];
        }
    }
    while (i < n1) {
        follower[k] = tempfol[i];
        arr[k++] = tempL[i++];
    }
    while (j < n2) {
        follower[k] = tempfol2[j];
        arr[k++] = tempR[j++];
    }
}
 
void mergeSort(int *arr,int *follower, int s, int e) {
    if (s >= e)
        return;
    int m = s + (e - s)/2;
    mergeSort(arr,follower, s, m);
    mergeSort(arr,follower, m + 1, e);
    merge(arr, follower,s, m, e);
}
void printA(int *arr, int n){
    for(int i =0; i<n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int n,m;
    // printf("enter n and m: ");
    scanf("%d",&n);
    scanf("%d\n", &m);
    int arr[m];
    int follower[m];
    
    for(int i =0; i<m; i++){
        scanf("%d", &arr[i]);
        scanf("%d\n", &follower[i]);
    }
    
    mergeSort(arr, follower,0, m - 1);    
    
    
    int ptr = arr[0];
    int chk  = 1;
    int q =0;
    while(chk<=n){
        if(chk == arr[q] && q < m ){
            printf("%d ", follower[q]);

            if(q < m - 1){
                if(arr[q+1] != arr[q]){
                    printf("\n");
                    chk++;
                }
            }
            else if(q == m - 1){
                printf("\n");
                chk++;
            }
            q++;
            continue;
        }
        else if (chk != arr[q]){
            printf("-1\n"); 
            chk++;
            continue;
        }
        // chk++;
        // if(chk == arr[q]){
        //     printf("\n%d", follower[q]);
        //     q++;
        // }
    }
    return 0;
} 
