#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TRAIN
{
    char BEGST[255]; //Destination
    int TERM; //Train number
    int TIME; //Departure time
};

int recordingCount = 0;

void show_menu(){
    printf("\nMENU:\n");
    printf("1. Add train data\n");
    printf("2. Sort train data\n");
    printf("3. Show all trains\n");
    printf("4. Search train\n");
    printf("5. Exit\n\n");
}

void* add_train_data(struct TRAIN *pTrain);
void sort_train_data(struct TRAIN *pTrain);
void show_all_trains(struct TRAIN *pTrain);
void search_train(struct TRAIN *pTrain);

int main(){
    struct TRAIN *pTrain = NULL;

    while (true) {
        int choice;

        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                pTrain = add_train_data(pTrain);
                if(pTrain == NULL) return 1;
                break;
            case 2:
                sort_train_data(pTrain);
                break;
            case 3:
                show_all_trains(pTrain);
                break;
            case 4:
                search_train(pTrain);
                break;
            case 5:
                printf("\nExiting...");
                break;
            default:
                printf("\nNo such option! Try again!");
                break;
        }
        
        if(choice == 5) break;
    }

    free(pTrain);

    return 0;
}
void show_all_trains(struct TRAIN *pTrain){
    printf("\nAll trains data:\n");
    for(int i = 0; i < recordingCount; i++){
        printf("\nRASP[%d]:\n", i);
        printf("BEGST: %s\n", (pTrain+i)->BEGST);
        printf("TERM: %d\n", (pTrain+i)->TERM);
        printf("TIME: %01d:%01d\n", (pTrain+i)->TIME / 100, (pTrain+i)->TIME % 100);
    }
}

void* add_train_data(struct TRAIN *pTrain){
    pTrain = (struct TRAIN*)realloc(pTrain, (recordingCount + 1) * sizeof(struct TRAIN));
    if(pTrain == NULL){
        printf("\nError allocating memory!");
        return NULL;
    }

    printf("\nTrain #%d\n", recordingCount);
    printf("Destination: ");
    scanf("%254s", (pTrain+recordingCount)->BEGST);
    printf("Train Number: ");
    scanf("%d", &((pTrain+recordingCount)->TERM));
    printf("Departure Time: ");
    scanf("%d", &((pTrain+recordingCount)->TIME));

    ++recordingCount;
    return pTrain;
}

void sort_train_data(struct TRAIN *pTrain){
    for(int i = 0; i < recordingCount; i++){
        for(int j = i+1; j < recordingCount; j++){
            if(((pTrain+i)->TERM) > (pTrain+j)->TERM){
                struct TRAIN temp = *(pTrain+j);
                *(pTrain+j) = *(pTrain+i);
                *(pTrain+i) = temp;
            }
        }
    }
}

void search_train(struct TRAIN *pTrain){
    printf("\nEnter train number to search: ");
    int searchTerm;
    scanf("%d", &searchTerm);
    if(searchTerm < 0){
        printf("\nError: train number cannot be negative.\n");
    } else {
        short found = 0;
        for(int i = 0; i < recordingCount; i++){
            if((pTrain+i)->TERM == searchTerm){
                printf("Train found:\n");
                printf("BEGST: %s\n", (pTrain+i)->BEGST);
                printf("TERM: %d\n", (pTrain+i)->TERM);
                printf("TIME: %d:%d\n", (pTrain+i)->TIME / 100, (pTrain+i)->TIME % 100);
                found = 1;
                break;
            }
        }
        if(!found){
            printf("\nTrain with number %d not found.\n", searchTerm);
        }
    }
}