#include <stdio.h>
#include <string.h>
#include "cvicenie_7.h"

int main(int argc, char * argv[]) {
    char input[MAX_DATA_SIZE];
    int maxlenslova = 50; //MAX Dlzka slova
    int maxslov = 100;

    char Slova[maxslov][maxlenslova];//char Slova[Poc_slov_inp][maxlenslova];

    loadText(input, MAX_DATA_SIZE); //zapise nam do input nas text, a vrati nam pocet znakov

    char input_pre_medzery[MAX_DATA_SIZE];
    strcpy(input_pre_medzery, input);

    int poc_medz = pocet_medzier(input);
    char Medziery[maxslov][poc_medz];

    zapis_medziery_do_pola(maxslov, poc_medz, Medziery, input_pre_medzery);

    pocet_slov(input); //pocet slov ktore su v nasom input

    int aaa = zapis_do_pola(maxslov, maxlenslova, Slova, input);

    rob_to_co_treba(argc, argv, maxslov, maxlenslova, Slova);

    for (int i = 0; i < aaa; ++i) {
        printf("%s%s", Slova[i], Medziery[i]);
    }

    return 0;
}