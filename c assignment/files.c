#include <stdio.h>
#define max 100
typedef struct{
    char name[50];
    char phone[40];
    char item[10][20];
    int no[10];
    int cost[10];
    int itemcount;
}customer;

int main(){
    customer c[max];
    char file[40];
    int k = 0;
    int choice;
    printf("Customer invoice System\n");
    printf("-----------------------\n");
    printf("1.Add Customer details\n");
    printf("2.View customer details\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
   
   switch(choice){
    case 1: {
    
    printf("enter number of customers:");
    scanf("%d",&k);
   
   for(int i=0;i<k;i++){
    printf("enter customer name:");
    scanf("%s",c[i].name);
    printf("enter customer phone number:");
    scanf("%s",c[i].phone);
    printf("enter number of items:");
    scanf("%d", &c[i].itemcount);
   
          for(int j=0;j<c[i].itemcount;j++){
            printf("enter item name:");
            scanf("%s",c[i].item[j]);
            printf("enter no. of items:");
            scanf("%d",&c[i].no[j]);
            printf("enter item cost:");
            scanf("%d",&c[i].cost[j]);
          }
          sprintf(file,"%s.txt",c[i].name);

          FILE * fp = fopen(file, "w");
          if (fp == NULL) {
              printf("Error opening file %s\n", file);
              return 1;
          }
            fprintf(fp, "Customer Name: %s\n", c[i].name);
            fprintf(fp, "Customer phone number:%s\n", c[i].phone);
            for(int j=0;j<c[i].itemcount;j++){
                fprintf(fp, "Item Name: %s\n", c[i].item[j]);
                fprintf(fp, "No. of items: %d\n", c[i].no[j]);
                fprintf(fp, "Item Cost: %d\n", c[i].cost[j]);
            }
            fclose(fp);
   }
           
            break;
}
            case 2: {
            printf("enter customer name to view details:");
            char cname[50];
            scanf("%s",cname);
            sprintf(file,"%s.txt",cname);
            FILE * fpr = fopen(file, "r");
            if (fpr == NULL) {
                printf("Error opening file %s\n", file);
                return 1;
            }
            char ch;
            while((ch = fgetc(fpr)) != EOF){
                putchar(ch);
            }
            fclose(fpr);
            break;
        }

        }

}


