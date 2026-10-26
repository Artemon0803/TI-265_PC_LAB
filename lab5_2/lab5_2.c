#include <stdio.h>
#include <string.h>

int main(){
    char str[] = "  Hello,   world!  Let's  write    some  code.  ";
    int gap = 0;
    int minGap = -1;
    int wordFound = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            if (wordFound) {
                gap++;
            }
        } else {
            if (gap > 0) {
                if (minGap == -1 || gap < minGap) {
                    minGap = gap;
                }
                gap = 0;
            }

            wordFound = 1;
        }
    }

    if (minGap == -1) {
        printf("No gap.\n");
    } else {
        printf("Min gap: %d\n", minGap);
    }

    return 0;
}