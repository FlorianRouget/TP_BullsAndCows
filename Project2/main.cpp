//inclure les Header Files
#include "BullsAndCows.h"

int main(int argc, char** argv) {

	BullsAndCows jeu; //itération de la classe BullsAndCows
	char c = '0'; //une variable pour récupérer un choix du joueur
	string repj = ""; //une string pour récupérer le mot proposé par le joueur

	do //une grosse boucle pour faire boucler le programme temps que le joueur veut continuer
	{
		jeu.reinit(); //on réinitialise les variables et on affiche le texte d'intro du jeu

		do //deuxième boucle qui représente le coeur du jeu, et qui re-boucle à chaque proposition du joueur
		{
			jeu.setCurrentTry(jeu.getCurrentTry() + 1); //on incrémente le nombre d'essai effectué
			jeu.afficheState(); //on affiche l'état de la partie
			cin >> repj; //on récupère l'input du joueur
			jeu.verifInput(repj); //on vérifie ce que le joueur vient de rentrer.
			
		} while ((jeu.getGameWon() != true)&&(jeu.getCurrentTry() < jeu.getMaxTry()));
		
		//lorsque la partie est finie, en fonction de la résolution on annonce le résultat au joueur
		if (jeu.getGameWon()) {
			cout << "Vous avez gagné, bien joué." << endl;
		} else {
			cout << "Vous avez perdu, trop mauvais." << endl;
		}

		//on lui demande ensuite s'il veut rejouer
		do
		{
			cout << "Nouvelle partie ? 1=OUI et 2=NON" << endl;
			cin >> c;
		} while ((c != '1')&&(c != '2'));

	} while (c == '1');

}

/*en focntion de la taille du mot, on a plus de tours et de choix. Pour un mot de 5 lettre, on aura 10 essais. Le but du jeu est de trouver
//le mot en constante. Si une lettre est correctement placée, on gagne un bull, si une lettre est présente dans le mot mais mal placée, on gagne une
//cow (motus). Interdit de mettre plusieurs fois la même lettre. On peut mettre le même mot plusieurs fois.
//pour définir le nombre d'essai par rapport au mot :

//DEADLINE :
//NEED :
- type structuré pour le Bull et pour le Cow
- un enum avec "invalid statut / ok / not isogram / wrong length / not lowercase", à retourner au joueur.
- classe objet avec 3 données membres : int MyCurrentTry ; string MyHiddenWord ; bool GameIsWon
- faire des fonctions pour tous les tests
- faut tout le jeu soit dans une classe
*/