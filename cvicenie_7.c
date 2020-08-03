//
// Created by Bestiae on 30.03.2019.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int loadText(char * input, int n){ //load data v input
    int i = 0;
    char znak;

    while((scanf("%c", &znak) != EOF) && (n > 0)){
        input[i] = znak;
        i++;
    }
    return i;
}

void rob_to_co_treba(int argc, char * argv[], int pocetslov, int maxlenslova, char Roz_slova[pocetslov][maxlenslova]){
    for(int i = 0; i < argc; i++){
        if(strchr(argv[i], '/') == NULL){ // ked nenasiel, rob ako cenzura!!!

                int dlzka_buf = strlen(argv[i]);
                char buf[dlzka_buf]; // pomocne pole charov pre nase slova cenzurove
                strcpy(buf, argv[i]);

                for(int j = 0; j < pocetslov; j++){
                    if(strcmp(buf, Roz_slova[j]) == 0){
                        for(int a = 0; a < strlen(buf); a++){
                            Roz_slova[j][a] = '*';
                        }
                    }
                }


        } else{ // rob ako Find/Replace
            int dlzka_buf = strlen(argv[i]);
            char buf[dlzka_buf]; // pomocne pole charov pre nase slova cenzurove
            strcpy(buf, argv[i]);
            //rozdelim slovo
            char *buf1, *buf2;
            char prazne[] = "";

            char sep[] = "/";
            char *istr;
            istr = strtok(buf, sep);
            buf1 = istr;
            while (istr != NULL){
                buf2 = istr;
                istr = strtok (NULL,sep);
            }
            //int lenbuf2 = strlen(buf2);

            for(int j = 0; j < pocetslov; j++){
                if(strcmp(buf1, Roz_slova[j]) == 0){
                    strcpy(Roz_slova[j], prazne);
                    strcpy(Roz_slova[j], buf2);
                }
            }
        }
    }
}

int pocet_medzier(char * input){
    int Poc_medzier = 0;
    for(int i = 0; i < strlen(input); i++){
        if(input[i] == 0x20){
            Poc_medzier++;
            //printf("je medziera, poc_m = %d\n", Poc_medzier);
        }
    }
    return Poc_medzier;
}

int pocet_slov(char * input){
    int Pocet_slov = 1;
    for(int i = 0; i < strlen(input); i++){
        if(input[i-1] == ' ' && input[i] != ' '){
            Pocet_slov++;
        }
    }
    return Pocet_slov;
}

int zapis_do_pola(int pocetslov, int maxlenslova, char Roz_slova[pocetslov][maxlenslova], char * input){
    char sep[] = "\n ";
    char *slovo;

    slovo = strtok(input, sep);

    int i = 0;
    while(slovo != NULL){
        strcpy(Roz_slova[i], slovo);
        i++;
        slovo = strtok(NULL, sep);
    }
    return i;
}

int zapis_medziery_do_pola(int maxslov, int maxlenslov, char Medziery[maxslov][maxlenslov], char * inputM){
    char sep1[] = "abcdefghijklmnopqrstuvwxyz1234567890";
    char *medziera;

    medziera = strtok(inputM, sep1);

    int i = 0;
    while(medziera != NULL){
        //printf("\"%s\"\n", medziera);
        strcpy(Medziery[i], medziera);
        i++;
        medziera = strtok(NULL, sep1);
    }
    return i;
}