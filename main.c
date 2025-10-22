#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int spørg() {
    bool fundet = false;
    bool foerst = true;
    bool spoerg = false;
    char reservedel[100];  // Buffer til input
    char *dele[] = { "hydraulic pump", "PLC module", "servo motor", NULL };
    char *spoergsmaal[] = {"har du faktisk nogle dele?" , "hvad har du paa lager?",NULL};

printf("Hej, velkommen til reservedel butikken. \n ");
    while (!fundet) {
        printf("Hvilken del har du brug for?  ");
        spoerg =false;
        // Læs hele linjen inklusive mellemrum og sætter det til reservedel. tager standardinputtet på maks 100 tegn
        if (fgets(reservedel, 100, stdin) == NULL) {
            // Hvis der sker en fejl ved input, afslut
            return 1;
        }

//søger efter \n som er i slut af input fra fgets, og fjerner ved at erstatte med 0 
        reservedel[strcspn(reservedel, "\n")]='\0';

//scanner hver linje i reservedel array og sammenligner med inputtet fra terminalen
        for (int i = 0; dele[i] != NULL; i++) {
            if (strcmp(dele[i], reservedel) == 0) {
                fundet = true;
                printf("Vi har den del :) \n");
                break;  // Stop løkken, når vi har fundet delen
            }
        }

        //tjekker om de spørger ind til lager
        for (int i = 0; spoergsmaal[i] != NULL; i++) {
            if(strcmp(spoergsmaal[i], reservedel) == 0){ //tjek om det er lager spørgsmåk
                printf("Vi har: \n");
                spoerg=true;
                for (int j = 0; dele[j] != NULL; j++) { //print dele
                printf("%d )  %s \n" ,j+1, dele[j]);
                }  
                break;             
            }
        }
        if (!fundet && !spoerg) {
            printf("Vi har desvaerre ikke %s blandt vores reservedele\n" ,reservedel );
        }
    }

    return 0;
}

int main() {
    spørg();
    return 0;
}