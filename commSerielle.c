/*
 * Nom du fichier :
 *    commSerielle.c
 * Description :
 *   Bibliothèque qui permet une connexion sérielle à un arduino
 * Historique :
 *    2020-11-26 Yanick Labelle   Entrée initiale du code.
 */
// ======================================== Fichiers d'inclusion =================================================
#include "commSerielle.h"

/* ==================================================================================================================
* Nom de la fonction :
* seriel_initialiser_connecter
* Description de la fonction :
* Cette fonction initialise les paramètre de la communication sérielle et effectue une connexion sérielle vers l'arduino
* Paramètre(s) d'entrée :
* 1. Un pointeur vers la structure commSerielle_t à utiliser
* 2. Une chaine de caractère désignant le port sériel à utiliser
* 3. Un entier non-signé désigant la vitesse de communication avec l'arduino
* Valeur de retour :
* Un nombre entier représentant un code d'erreur :
* 0 : Aucun problème à signaler
* -1 : Une erreur est survenue
* Note(s) :
* Aucunes
*
* Historique :
* 2021-11-26 Yanick Labelle Entrée initiale du code.
* ==================================================================================================================
*/
int seriel_initialiser_connecter(commSerielle_t* commSerielle, char* sCom, unsigned int baudRate){

    HANDLE portSeriel;

    commSerielle->sCom = sCom;
    commSerielle->handle = portSeriel;
    commSerielle->parametres.BaudRate = baudRate;
    commSerielle->parametres.ByteSize = 8;
    commSerielle->parametres.StopBits = ONESTOPBIT;
    commSerielle->parametres.Parity = NOPARITY;

    commSerielle->handle = CreateFileA(commSerielle->sCom, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

    if(commSerielle->handle == INVALID_HANDLE_VALUE || SetCommState(commSerielle->handle, &commSerielle->parametres) == 0 || SetCommMask(commSerielle->handle, EV_RXCHAR) == 0)
    {
        CloseHandle(commSerielle->handle);
        return -1;
    }
    return 0;
}

/* ==================================================================================================================
* Nom de la fonction :
* seriel_lireDonnees
* Description de la fonction :
* Cette fonction lit les données présentes sur le port sériel
* Paramètre(s) d'entrée :
* 1. Un pointeur vers la structure commSerielle_t à utiliser
* 2. Une chaine de caractère contenant la valeur lue sur le port sériel
* 3. Un entier définissant le nombre de caractère maximum à mettre dans le buffer
* Valeur de retour :
* Un nombre entier représentant un code d'erreur :
* 0 : Aucun problème à signaler
* -1 : Une erreur est survenue
* Note(s) :
* Aucunes
*
* Historique :
* 2021-11-26 Yanick Labelle Entrée initiale du code.
* ==================================================================================================================
*/
int seriel_lireDonnees(commSerielle_t* commSerielle, char* sBuffer, int iNombreCharacteres){

    DWORD typeEvenement = 0;

    WaitCommEvent(commSerielle->handle, &typeEvenement, NULL);
    if (typeEvenement & EV_RXCHAR)
    {
        if (ReadFile(commSerielle->handle, sBuffer, iNombreCharacteres, NULL, NULL) == 0)
        {
            return -1;
        }
        else
        {
            strncpy_s(sBuffer, sizeof sBuffer,sBuffer, (sizeof sBuffer)-1);
        }
    }
    return 0;
}

/* ==================================================================================================================
* Nom de la fonction :
* seriel_envoyerDonnees
* Description de la fonction :
* Cette fonction créer un fichier et écrit les données qui sont présentes dans la structure en paramètre d'entrée.
* Paramètre(s) d'entrée :Serielle_t à utiliser
* 1. Un pointeur vers la structure commSerielle_t à utiliser
* 2. Une chaine de caractère contenant la valeur à envoyer sur le port sériel
* 3. Un entier définissant le nombre de caractère maximum à mettre dans le buffer
* Valeur de retour :
* Un nombre entier représentant un code d'erreur :
* 0 : Aucun problème à signaler
* -1 : Une erreur est survenue
* Note(s) :
* Aucunes
*
* Historique :
* 2021-11-26 Yanick Labelle Entrée initiale du code.
* ==================================================================================================================
*/
int seriel_envoyerDonnees(commSerielle_t* commSerielle, char* sBuffer, int iNombreCharacteres){
    if (WriteFile(commSerielle->handle, sBuffer, iNombreCharacteres, NULL, NULL) == 0)
    {
        return -1;
    }
        return 0;
}