#include <stdio.h>
#include <string.h>
int main(){
     int num[50];
     int i;
    FILE *ty = fopen("nums.txt", "w");
     for(int i=0; i<10; i++){
        printf("enter %d number: ", i+1);
        scanf("%d" ,&num[i]);
           fprintf(ty, "%d\n",num[i]);
    }

     fclose(ty);
     printf("successfully wrote to nums.txt");
}
