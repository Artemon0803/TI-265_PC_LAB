#include <stdio.h>

struct TRAIN
{
    char BEGST[255]; //Destination
    int TERM; //Train number
    int TIME; //Departure time
};

int main(){
    struct TRAIN RASP[3];

    for(int i = 0; i < 3; i++){
        printf("Train #%d\n", i);
        printf("Destination: ");
        scanf("%254s", RASP[i].BEGST);
        printf("Train Number: ");
        scanf("%d", &RASP[i].TERM);
        printf("Departure Time: ");
        scanf("%d", &RASP[i].TIME);
    }

    for(int i = 0; i < 3; i++){
        for(int j = i; j < 3; j++){
            if(RASP[i].TERM > RASP[j].TERM){
                struct TRAIN temp = RASP[i];
                RASP[i] = RASP[j];
                RASP[j] = temp;
            }
        }
    }

    printf("\nSorted array:\n");
    for(int i = 0; i < 3; i++){
        printf("RASP[%d]:\n", i);
        printf("BEGST: %s\n", RASP[i].BEGST);
        printf("TERM: %d\n", RASP[i].TERM);
        printf("TIME: %02d:%02d\n", RASP[i].TIME / 100, RASP[i].TIME % 100);
    }

    printf("\n Enter train number to search: ");
    int searchTerm;
    scanf("%d", &searchTerm);
    if(searchTerm < 0){
        printf("Error: train number cannot be negative.\n");
    } else {
        short found = 0;
        for(int i = 0; i < 3; i++){
            if(RASP[i].TERM == searchTerm){
                printf("Train found:\n");
                printf("BEGST: %s\n", RASP[i].BEGST);
                printf("TERM: %d\n", RASP[i].TERM);
                printf("TIME: %02d:%02d\n", RASP[i].TIME / 100, RASP[i].TIME % 100);
                found = 1;
                break;
            }
        }
        if(!found){
            printf("Train with number %d not found.\n", searchTerm);
        }
    }

    return 0;
}