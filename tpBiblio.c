// TP GESTION D'UNE BIBLIOTHEQUE 
#include "biblio.h"

T_Aut auteur;
T_Titre titre;

int menu()
{
	int choix;
// au programme du TP7 :
printf("\n\n 1 - ajouter un nouveau livre dans la bibliotheque "); 
printf("\n 2 - afficher tous les livres de la bibliotheque "); 
printf("\n 3 - rechercher un livre (par son titre)");  // il peut y avoir plusieurs livres de même titre. Dans ce cas, indiquez le nombre d'exemplaires disponibles
printf("\n 4 - rechercher et afficher tous les livres d'un auteur");
printf("\n 5 - supprimer un livre de la bibliotheque");
// si les 5 choix ci dessus sont bien codés, modifiez votre structure T_Livre et passez à 5 champs (avec cote,editeur et annee)


// au programme du TP8 :
// ajouter le champ emprunteur à votre structure T_Livre
/*
printf("\n 6 - emprunter un livre de la bibliotheque");
printf("\n 7 - restituer/rendre un livre de la bibliotheque");
printf("\n 8 - trier les livres (par titre)");
printf("\n 9 - trier les livres (par auteur)");
printf("\n 10 - trier les livres (par annee)");
*/
// si les 5 choix (6-10) sont bien codés, changez le type T_Emp et remplacez-le par la structure T_Emp visible dans livre.h
// vous pourrez alors faire les menus 11,12,etc...
// printf("\n 11- lister les livres disponibles "); 
// printf("\n 12 - lister les emprunts en retard "); //on suppose qu'un emprunt dure 7 jours.
// printf("\n 13 - ... imaginez vous même vos propres fonctionnalités ")

printf("\n 0 - QUITTER");
printf("\n Votre choix : ");
scanf("%d[^\n]",&choix);getchar();
return choix;


}



int main()
{
	int reponse,chx;
	T_Bibliotheque B; 
	init(&B);
	chargement(&B);

	do
	{
		chx= menu();
		switch(chx)
		{
		case  1 : reponse = ajouterLivre(&B);
					if (reponse==OK)
						printf("Ajout reussi !!");
					else
						printf("Impossible d ajouter (bibliotheque pleine)");
				break;
		case 2 : reponse=afficherBibliotheque(&B);
				if (reponse==PAS_OK)	
						printf("La bibliotheque est vide");

				break;	
		case 3:
			lireChaine("titre :", titre, K_MaxTit);

			rechercherLivreParTitre(&B, titre); 
			break;
		case 4: 
			lireChaine("auteur :", auteur, K_MaxAut);

			rechercherLivresParAuteur(&B, auteur); 
			break;
		case 5:
			lireChaine("titre :", titre, K_MaxTit);

			int result = supprimerLivre(&B, titre);
			if (result == PAS_OK)
				printf("ERREUR : Livre non supprimé !");
			else
				printf("Livre supprimé !");
			break;
		default:
			printf("Entrée incorrecte ! Veuillez rééssayer\n\n");
			break;
		}

	}while(chx!=0);

	sauvegarde(&B);

	return 0;

}
