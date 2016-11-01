#pragma once
#include <iostream>
#include <string>
#include <map>
#include <ctype.h>

using namespace std;

typedef struct BullCow
{
	int nbBulls; //contiendra le nombre de Bulls
	int nbCows; //contiendra le nombre de Cows
}BullCow;

enum GameStatut {
	//les diff�rents statuts du jeu
	invalidstatut,
	ok,
	notisogram,
	wronglength,
	notlowercase

};


class BullsAndCows
{

private:
	int MyCurrentTry; //contient l'indice de l'essai en cours
	int MaxTry; //contient le nombre d'essais max
	string MyHiddenWord; //contient le mot � trouver
	bool GameIsWon; //un bool�en pour permettre au jeu de s'arr�ter m�me s'il y a encore des essais
	BullCow Score; //l'instance de mon type structur�, qui contient le nombre de Bulls et de Cows
	GameStatut GStatut; //l'instance de mon �num�ration g�rant les statuts d'erreur


public:
	BullsAndCows();
	~BullsAndCows();
	//global
	int GetMaxTries() const;
	void afficheState() const;
	string generatedWort();
	void reinit();
	void isVictory();
	//mutateurs
	//get
	int getCurrentTry() const;
	int getMaxTry() const;
	string getHiddenWord() const;
	bool getGameWon() const;
	int getBulls() const;
	int getCows() const;
	//set
	void setCurrentTry(int nv);
	void setHiddenWord(string nv);
	void setGameWon(bool nv);
	void setBulls(int nv);
	void setCows(int nv);
	//gestion d'erreur et des scores
	void defineBullsCows(string motj);
	void verifInput(string motj);
	void verifCase(string motj);
	void verifIsogram(string motj);
	void verifLength(string motj);

};

