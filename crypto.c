#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
   char message[100];
   char choice;
   srand(time(NULL));

   do{
        int key = (rand()%25) + 1;
        printf("current curse:%d\n", key);
   printf("enter your message:");
   scanf(" %[^\n]",message);
   for(int i=0; message[i] != '\0'; i++){
        if(message[i] >= 'a' && message[i] <= 'z'){
    message[i] =((message[i]- 'a' + key)%26) + 'a';
        }else if(message[i] >= 'A' && message[i] <= 'Z'){
    message[i] =((message[i]- 'A' + key)%26) + 'A';
        }
   }
   printf("%s\n", message);
   printf("would you like to encrypt another message:");
   scanf(" %c",&choice);
   }while(choice == 'y' || choice == 'Y');
   return 0;
}
// Simple Caesar Cipher Encryption Program

