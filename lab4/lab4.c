#include <stdio.h>

struct TRAIN
{
    char BEGST[255];
    int TERM;
    int TIME;
};

int main(){
    struct TRAIN RASP[3];

    for(int i = 0; i < 3; i++){
        printf("Поезд #%d\n", i);
        printf("Введите пункт назначения: ");
        scanf("%254s", RASP[i].BEGST);
        printf("Введите номер поезда: ");
        scanf("%d", &RASP[i].TERM);
        printf("Введите время отправления: ");
        scanf("%d", &RASP[i].TIME);
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3 - i - 1; j++){
            if(RASP[j].TERM > RASP[j + 1].TERM){
                struct TRAIN temp = RASP[j];
                RASP[j] = RASP[j + 1];
                RASP[j + 1] = temp;
            }
        }
    }

    printf("\nОтсортированный массив:\n");
    for(int i = 0; i < 3; i++){
        printf("RASP[%d]:\n", i);
        printf("BEGST: %s\n", RASP[i].BEGST);
        printf("TERM: %d\n", RASP[i].TERM);
        printf("TIME: %d:%d\n", RASP[i].TIME / 100, RASP[i].TIME % 100);
    }

    printf("\nВведите номер поезда для поиска: ");
    int searchTerm;
    scanf("%d", &searchTerm);
    if(searchTerm < 0){
        printf("Ошибка: номер поезда не может быть отрицательным.\n");
    } else {
        short found = 0;
        for(int i = 0; i < 3; i++){
            if(RASP[i].TERM == searchTerm){
                printf("Поезд найден:\n");
                printf("BEGST: %s\n", RASP[i].BEGST);
                printf("TERM: %d\n", RASP[i].TERM);
                printf("TIME: %d:%d\n", RASP[i].TIME / 100, RASP[i].TIME % 100);
                found = 1;
                break;
            }
        }
        if(!found){
            printf("Поезд с номером %d не найден.\n", searchTerm);
        }
    }

    return 0;
}
