#ifndef TESTBIBLIOSERIELLE_COMMSERIELLE_H
#define TESTBIBLIOSERIELLE_COMMSERIELLE_H

#endif //TESTBIBLIOSERIELLE_COMMSERIELLE_H

#include <stdio.h>
#include <windows.h>
#include <conio.h>

typedef struct commSerielle_t {
    char* sCom ;
    HANDLE handle ;
    DCB parametres;
}commSerielle_t;

int seriel_initialiser_connecter(commSerielle_t* commSerielle, char* sCom, unsigned int baudRate);
int seriel_lireDonnees(commSerielle_t* commSerielle, char* sBuffer, int iNombreCharacteres);
int seriel_envoyerDonnees(commSerielle_t* commSerielle, char* sBuffer, int iNombreCharacteres);