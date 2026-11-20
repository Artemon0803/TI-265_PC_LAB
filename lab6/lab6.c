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
    printf("2. Delete train data\n");
    printf("3. Sort train data\n");
    printf("4. Show all trains\n");
    printf("5. Search train\n");
    printf("6. Exit\n\n");
}

void show_train_data(struct TRAIN *pTrain, int i);
void* add_train_data(struct TRAIN *pTrain);
void* delete_train(struct TRAIN *pTrain);
void sort_train_data(struct TRAIN *pTrain);
void show_all_trains(struct TRAIN *pTrain);
short search_train(struct TRAIN *pTrain);

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
                pTrain = delete_train(pTrain);
                break;
            case 3:
                sort_train_data(pTrain);
                break;
            case 4:
                show_all_trains(pTrain);
                break;
            case 5:
                int index = search_train(pTrain);
                if(index != -1) show_train_data(pTrain, index);
                break;
            case 6:
                printf("\nExiting...");
                break;
            default:
                printf("\nNo such option! Try again!");
                break;
        }
        
        if(choice == 6) break;
    }

    free(pTrain);

    return 0;
}

void show_train_data(struct TRAIN *pTrain, int i){
    if (recordingCount == 0) {
        printf("\nNo trains to show.\n");
        return;
    }

    printf("\nRASP[%d]:\n", i);
    printf("BEGST: %s\n", (pTrain+i)->BEGST);
    printf("TERM: %d\n", (pTrain+i)->TERM);
    printf("TIME: %02d:%02d\n", (pTrain+i)->TIME / 100, (pTrain+i)->TIME % 100);
}

void show_all_trains(struct TRAIN *pTrain){
    if (recordingCount == 0) {
        printf("\nNo trains to show.\n");
        return;
    }

    printf("\nAll trains data:\n");
    for(int i = 0; i < recordingCount; i++){
        printf("\nRASP[%d]:\n", i);
        printf("BEGST: %s\n", (pTrain+i)->BEGST);
        printf("TERM: %d\n", (pTrain+i)->TERM);
        printf("TIME: %02d:%02d\n", (pTrain+i)->TIME / 100, (pTrain+i)->TIME % 100);
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
    if (recordingCount == 0) {
        printf("\nNo trains to sort.\n");
        return;
    }

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

short search_train(struct TRAIN *pTrain){
    if (recordingCount == 0) {
        printf("\nNo trains to search.\n");
        return -1;
    }

    printf("\nEnter train number to search: ");
    int searchTerm;
    scanf("%d", &searchTerm);
    if(searchTerm < 0){
        printf("\nError: train number cannot be negative.\n");
    } else {
        short found = 0;
        for(int i = 0; i < recordingCount; i++){
            if((pTrain+i)->TERM == searchTerm){
                found = i;
                break;
            }
        }
        if(!found){
            printf("\nTrain with number %d not found.\n", searchTerm);
            return -1;
        } else {
            return found;
        }
    }
}

void* delete_train(struct TRAIN *pTrain){
    if (recordingCount == 0) {
        printf("\nNo trains to delete.\n");
        return pTrain;
    }

    int trainNumber;
    printf("\nEnter train number to delete: ");
    if (scanf("%d", &trainNumber) != 1) {
        printf("\nInvalid train number.\n");
        return pTrain;
    }

    int index = -1;
    for (int i = 0; i < recordingCount; i++) {
        if (pTrain[i].TERM == trainNumber) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("\nTrain with number %d not found.\n", trainNumber);
        return pTrain;
    }

    for (int i = index; i < recordingCount - 1; i++) {
        pTrain[i] = pTrain[i + 1];
    }
    recordingCount--;

    if (recordingCount == 0) {
        free(pTrain);
        printf("\nAll trains deleted.\n");
        return NULL;
    }

    struct TRAIN *resized = realloc(pTrain, recordingCount * sizeof *pTrain);
    if (resized == NULL) {
        printf("\nTrain deleted, but memory could not be reduced.\n");
        return pTrain;
    }

    printf("\nTrain deleted.\n");
    return resized;
}