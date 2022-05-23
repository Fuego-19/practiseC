#include <stdio.h>

int guest[];
int follower[];

int main(){
    int n,m;
    guest[m];
    follower[m];
    scanf("%d",&n);
    scanf("%d\n", &m);

    
    for(int i =0; i<m; i++){
        scanf("%d", &guest[i]);
        scanf("%d\n", &follower[i]);
    }

    return 0;
} 




// void mergeSort(int arr[], int S, int E){
//     int mid = (int)((S + E)/2);

//     mergeSort(arr, S, mid);
//     mergeSort(arr, mid + 1, E);
//     return merge(arr, S, E);
// }