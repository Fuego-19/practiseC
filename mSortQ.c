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
        follower[k] = tempfol[j];
        arr[k++] = tempR[j++];
    }
}
 
void mergeSort(int *arr,int *follower, int s, int e) {
    if (s >= e)
        return;
    int m = s + (e - s)/2;
    mergeSort(arr, s, m, follower);
    mergeSort(arr, m + 1, e, follower);
    merge(arr, s, m, e, follower);
}
int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
int main(){
    int n,m;
    int arr[m];
    int follower[m];
    printf("enter n and m: ");
    scanf("%d",&n);
    scanf("%d\n", &m);

    
    for(int i =0; i<m; i++){
        scanf("%d", &arr[i]);
        scanf("%d\n", &follower[i]);
    }
    
    for(int j =0; j<m; j++){
        printf("%d ", arr[j]);
    }

    mergeSort(arr,0, m - 1, follower);

    for(int j =0; j<m; j++){
        printf("%d ", arr[j]);
    }

    return 0;
} 
