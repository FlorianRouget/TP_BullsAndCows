//inclure les Header Files
#include "BullsAndCows.h"

int main(int argc, char** argv) {

	BullsAndCows jeu; //it�ration de la classe BullsAndCows
	char c = '0'; //une variable pour r�cup�rer un choix du joueur
	string repj = ""; //une string pour r�cup�rer le mot propos� par le joueur

	do //une grosse boucle pour faire boucler le programme temps que le joueur veut continuer
	{
		jeu.reinit(); //on r�initialise les variables et on affiche le texte d'intro du jeu

		do //deuxi�me boucle qui repr�sente le coeur du jeu, et qui re-boucle � chaque proposition du joueur
		{
			jeu.setCurrentTry(jeu.getCurrentTry() + 1); //on incr�mente le nombre d'essai effectu�
			jeu.afficheState(); //on affiche l'�tat de la partie
			cin >> repj; //on r�cup�re l'input du joueur
			jeu.verifInput(repj); //on v�rifie ce que le joueur vient de rentrer.
			
		} while ((jeu.getGameWon() != true)&&(jeu.getCurrentTry() < jeu.getMaxTry()));
		
		//lorsque la partie est finie, en fonction de la r�solution on annonce le r�sultat au joueur
		if (jeu.getGameWon()) {
			cout << "Vous avez gagn�, bien jou�." << endl;
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
//le mot en constante. Si une lettre est correctement plac�e, on gagne un bull, si une lettre est pr�sente dans le mot mais mal plac�e, on gagne une
//cow (motus). Interdit de mettre plusieurs fois la m�me lettre. On peut mettre le m�me mot plusieurs fois.
//pour d�finir le nombre d'essai par rapport au mot :

//DEADLINE :
//NEED :
- type structur� pour le Bull et pour le Cow
- un enum avec "invalid statut / ok / not isogram / wrong length / not lowercase", � retourner au joueur.
- classe objet avec 3 donn�es membres : int MyCurrentTry ; string MyHiddenWord ; bool GameIsWon
- faire des fonctions pour tous les tests
- faut tout le jeu soit dans une classe
*/