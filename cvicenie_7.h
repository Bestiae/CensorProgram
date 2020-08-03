//
// Created by Bestiae on 30.03.2019.
//

#ifndef UNTITLED1_CVICENIE_7_H
#define UNTITLED1_CVICENIE_7_H

#define MAX_DATA_SIZE 40000

int loadText(char * input, int n);

int pocet_slov(char * input);
int zapis_do_pola(int pocetslov, int maxlenslova, char Roz_slova[pocetslov][maxlenslova], char * input);

void rob_to_co_treba(int argc, char * argv[], int pocetslov, int maxlenslova, char Roz_slova[pocetslov][maxlenslova]);

int pocet_medzier(char * input);
int zapis_medziery_do_pola(int maxslov, int maxlenslov, char Medziery[maxslov][maxlenslov], char * input);

#endif //UNTITLED1_CVICENIE_7_H