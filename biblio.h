#ifndef BIBLIO_H   //compilation conditionnelle
#define BIBLIO_H
#define OK 1
#define PAS_OK -1

#include "livre.h"

#define CAPACITE_BIBLIO 20 // nb maximum de livres ds la bibliotheque

typedef  T_livre 	T_tabloDeLivres[CAPACITE_BIBLIO];

typedef struct
{
	T_tabloDeLivres etagere;
	int nbLivres;  //nb de livres actuellement ds la bibliotheque

} T_Bibliotheque;


//prototypes
void init (T_Bibliotheque *ptrB);
int ajouterLivre(T_Bibliotheque  *ptrB);
int afficherBibliotheque(const T_Bibliotheque  *ptrB);
int supprimerLivre(T_Bibliotheque *ptrB, const char* titre );
int rechercherLivresParAuteur(const T_Bibliotheque *ptrB, const char * auteur);
int rechercherLivreParTitre(const T_Bibliotheque *ptrB, const char * titre);

void sauvegarde(T_Bibliotheque *ptrB);
void chargement(T_Bibliotheque *ptrB);
void lectureFichierTXT();

#endif
