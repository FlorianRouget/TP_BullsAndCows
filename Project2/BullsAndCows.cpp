#include "BullsAndCows.h"


//constructeur
//initialisation de toutes les variables des données membres
BullsAndCows::BullsAndCows()
{
	MyCurrentTry = 0;
	MyHiddenWord = generatedWort();
	MaxTry = GetMaxTries();
	GameIsWon = false;
	GStatut = GameStatut::ok;
	this->Score.nbBulls = 0;
	this->Score.nbCows = 0;
}

//destructeur
BullsAndCows::~BullsAndCows()
{
}

//ENTREE : rien
//SORTIE : Le nombre d'essais maximum (entier)
//BUT : déterminer, en fonction de la longueur du mot caché, le nombre d'essais max auquel aura droit le joueur
int BullsAndCows::GetMaxTries() const
{
	std::map<int, int> WordLengthToMaxTries{ { 3,4 },{ 4,7 },{ 5,10 },{ 6,16 },{ 7,20 } };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

//ENTREE : rien
//SORTIE : rien
//BUT : afficher l'état actuel des Score, et le nombre d'essai
void BullsAndCows::afficheState() const
{
	cout << "Essai " << getCurrentTry() << " sur " << getMaxTry() << endl;
	cout << "Bulls : " << getBulls() << " ; Cows : " << getCows() << endl;
	cout << "Entrez un mot (" << getHiddenWord().length() << " lettres): " << endl;
}

//ENTREE : rien
//SORTIE : le nouveau mot secret à trouver
//BUT : la fonction choisit aléatoirement parmi une liste pré-établie le nouveau mot secret à faire deviner.
string BullsAndCows::generatedWort()
{
	int val = 0;
	string result;

	val = rand() % 10 + 1;
	switch (val)
	{
	case 1: result = "plume" ; break;
	case 2: result = "poids" ; break;
	case 3: result = "grand" ; break;
	case 4: result = "valide" ; break;
	case 5: result = "vue" ; break;
	case 6: result = "argon" ; break;
	case 7: result = "souple" ; break;
	case 8: result = "oui" ; break;
	case 9: result = "joint" ; break;
	case 10: result = "prenoms" ; break;
	default:
		break;
	}
	return result;
}

//ENTREE : rien
//SORTIE : rien
//BUT : cette fonction sert principalement à réinitialiser les variables en début de partie
void BullsAndCows::reinit()
{
	MyCurrentTry = 0;
	MyHiddenWord = generatedWort();
	MaxTry = GetMaxTries();
	GameIsWon = false;
	GStatut = GameStatut::ok;
	this->Score.nbBulls = 0;
	this->Score.nbCows = 0;

	cout << "Bonjour, on va jouer à un jeu." << endl;
	cout << "Vous allez devoir deviner un mot, et vous aurez un nombre d'essais restreint pour deviner de quel mot il s'agit." << endl;
	cout << "Pour vous aider, nous vous indiquerons le nombre de lettres bien placées (Bulls), et le nombre de lettres présentes mais mal placées (Cows)." << endl;
	cout << "GL HF batard." << endl;
}

//ENTREE : rien
//SORTIE : rien
//BUT : modifie la variable GameIsWon en fonction du nombre de Bulls. S'il y a le bon nombre de Bulls, on valide la victoire.
void BullsAndCows::isVictory()
{
	if (this->getBulls() == this->MyHiddenWord.length())
	{
		this->setGameWon(true);
	}
}

//ENTREE : rien
//SORTIE : la valeur de MyCurrentTry
//BUT : mutateur permettant d'obtenir la valeur de MyCurrentTry
int BullsAndCows::getCurrentTry() const
{
	return this->MyCurrentTry;
}

//ENTREE : rien
//SORTIE : la valeur de MaxTry
//BUT : mutateur permettant d'obtenir la valeur de MaxTry
int BullsAndCows::getMaxTry() const
{
	return this->MaxTry;
}

//ENTREE : rien
//SORTIE : la valeur de MyHiddenWord
//BUT : mutateur permettant d'obtenir la valeur de MyHiddenWord
string BullsAndCows::getHiddenWord() const
{
	return this->MyHiddenWord;
}

//ENTREE : rien
//SORTIE : la valeur de GameIsWon
//BUT : mutateur permettant d'obtenir la valeur de GameIsWon
bool BullsAndCows::getGameWon() const
{
	return this->GameIsWon;
}

//ENTREE : rien
//SORTIE : la valeur de nbBulls
//BUT : mutateur permettant d'obtenir la valeur de nbBulls
int BullsAndCows::getBulls() const
{
	return this->Score.nbBulls;
}

//ENTREE : rien
//SORTIE : la valeur ce nbCows
//BUT : mutateur permettant d'obtenir la valeur de nbCows
int BullsAndCows::getCows() const
{
	return this->Score.nbCows;
}

//ENTREE : un entier
//SORTIE : rien
//BUT : mutateur permettant de donner une nouvelle valeur au CurrentTry
void BullsAndCows::setCurrentTry(int nv)
{
	this->MyCurrentTry = nv;
}

//ENTREE : une chaine de caractère
//SORTIE : rien
//BUT : mutateur permettant de donner une nouvelle valeur au HiddenWord
void BullsAndCows::setHiddenWord(string nv)
{
	this->MyHiddenWord = nv;
}

//ENTREE : un booléen
//SORTIE : rien
//BUT : mutateur permettant de donner une nouvelle valeur au GameIsWon
void BullsAndCows::setGameWon(bool nv)
{
	this->GameIsWon = nv;
}

//ENTREE : un entier
//SORTIE : rien
//BUT : mutateur permettant de donner une nouvelle valeur au nbBulls
void BullsAndCows::setBulls(int nv)
{
	this->Score.nbBulls = nv;
}

//ENTREE : un entier
//SORTIE : rien
//BUT : mutateur permettant de donner une nouvelle valeur au nbCows
void BullsAndCows::setCows(int nv)
{
	this->Score.nbCows = nv;
}

//ENTREE : un mot entré par le joueur
//SORTIE : rien
//BUT : calculer le nombre de Bulls et de Cows en comparant le HiddenWord et le mot en entrée
void BullsAndCows::defineBullsCows(string motj)
{
	for (size_t i = 0; i < MyHiddenWord.length(); i++)
	{
		for (size_t j = 0; j < MyHiddenWord.length(); j++)
		{
			if (MyHiddenWord[i] == motj[j])
			{
				if (i == j) {
					this->setBulls(this->getBulls() + 1);
				}
				else
				{
					this->setCows(this->getCows()+1);
				}
			}
		}
	}
	this->isVictory();

}

//ENTREE : un mot entré par le joueur
//SORTIE : rien
//BUT : il s'agit d'un hub qui effectue plusieurs vérification (Lowercase, Isogram, Length) et qui renvoi un message d'erreur le cas échéant.
//		S'il n'y a pas d'erreur, la fonction va plutôt appeler la fonction de calcul des scores (defineBullsCows)
void BullsAndCows::verifInput(string motj)
{
	this->setBulls(0);
	this->setCows(0);
	this->GStatut = GameStatut::ok;
	verifCase(motj);
	verifIsogram(motj);
	verifLength(motj);
	
	switch (this->GStatut)
	{
		//case 0: cout << "lol" << endl; break;
		case 1: this->defineBullsCows(motj); break; //ok
		case 2: cout << "Votre mot n'est pas un isogram." << endl; break;
		case 3: cout << "La longueur de votre mot est inappropriée." << endl; break;
		case 4: cout << "Votre mot n'a pas que des caractères minuscules." << endl; break;
		default: cout << "default value" << endl;
		break;
	}

}

//ENTREE : un mot entré par le joueur
//SORTIE : rien
//BUT : une fonction pour vérifier que toutes les lettres sont en minuscule. Si ce n'est pas le cas, on passe le GameStatut à "notLowerCase"
void BullsAndCows::verifCase(string motj)
{
	for (size_t i = 0; i < motj.length(); i++)
	{
		if (isupper(motj[i]))
		{
			this->GStatut = GameStatut::notlowercase;
		}
	}
}

//ENTREE : un mot entré par le joueur
//SORTIE : rien
//BUT : une fonction pour vérifier qu'il n'y a pas deux fois la même lettre. Si ce n'est pas le cas, on passe le GameStatut à "notIsogram"
void BullsAndCows::verifIsogram(string motj)
{

	for (size_t i = 0; i < motj.length(); i++)
	{
		for (size_t j = 0; j < motj.length(); j++)
		{
			if ((motj[i] == motj[j])&&(i != j))
			{
				this->GStatut = GameStatut::notisogram;
			}
		}
	}

}

//ENTREE : un mot entré par le joueur
//SORTIE : rien
//BUT : une fonction pour vérifier que la longueur du mot est correcte. Si ce n'est pas le cas, on passe le GameStatut à "wrongLength"
void BullsAndCows::verifLength(string motj)
{
	if (motj.length() != MyHiddenWord.length())
	{
		this->GStatut = GameStatut::wronglength;
	}
}