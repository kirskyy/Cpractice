//SCS3/2498/2025
#include <stdio.h>

#define MAX 50

typedef struct {
    int oID;
    char Name[50];
    float cons;
    float bill;
} House;

float cbill(float cons) {
    float bill = 0;

    if (cons <= 10) {
        bill = cons * 50;
    }
    else if (cons <= 30) {
        bill = (10 * 50) + ((cons - 10) * 75);
    }
    else {
        bill = (10 * 50) + (20 * 75) + ((cons - 30) * 100);
    }
    return bill;
}

int main() {
    House house[MAX];
    int count = 0;
    int choice;

    do {
        printf("enter the choice you would like to make;\n1.enter household data\n2.display all households with bills\n3.compute and display average water consumption\n4.exit");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            if (count >= MAX) {
                printf("invalid\n");
                break;
            }

    printf("Enter owner ID: ");
    scanf("%d", &house[count].oID);

    printf("Enter Owner Name: ");
    scanf(" %[^\n]", house[count].Name);

    printf("Enter Monthly Water Consumption (m^3): ");
    scanf("%f", &house[count].cons);

    house[count].bill =
            cbill(house[count].cons);
            printf("record added.\n");
            count++;
            break;

        case 2:
            if (count == 0) {
                printf("No household records available.\n");
                break;
            }

            for (int i = 0; i < count; i++) {
                printf("\nHousehold %d\n", i + 1);
                printf("ID: %d\n", house[i].oID);
                printf("Owner: %s\n", house[i].Name);
                printf("Consumption: %.2f\n", house[i].cons);
                printf("Bill: Kes %.2f\n", house[i].bill);
            }
            break;

        case 3:
            if (count == 0) {
                printf("invalid\n");
                break;
            }

            float totalcons = 0;
            float maxbill = house[0].bill;
            float minbill = house[0].bill;
            int maxindex = 0;
            int minindex = 0;

            for (int i = 0; i < count; i++) {
                totalcons += house[i].cons;

                if (house[i].bill > maxbill) {
                    maxbill = house[i].bill;
                    maxindex = i;
                }

                if (house[i].bill < minbill) {
                    minbill = house[i].bill;
                    minindex = i;
                }
            }

            printf("\nAverage Water Consumption: %.2f\n",
                   totalcons / count);
            printf("Highest Bill: %s  %.2f\n",
                   house[maxindex].Name, maxbill);
            printf("Lowest Bill: %s (KES %.2f)\n",
                   house[minindex].Name, minbill);
            break;

        case 4:
            printf("program exited\n");
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (choice != 4);

    return 0;
}

