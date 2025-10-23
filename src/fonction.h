#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

typedef struct {
    int value; // La valeur de la carte (1 pour As, 2 pour 2, ..., 11 pour J, 12 pour Q, 13 pour K)
    char type; // C=carreaux, P=piques, H=coeurs,T=trefles

} Card;
 struct element{
    Card card;
    struct element *next;
};
typedef struct element element,*Pile;

Pile empiler(Pile p, Card c);
Card depilerCard(Pile *p);
Pile depiler(Pile p);
int longueur(Pile p);
void Color(int ctext,int cfond);
void remplirTableCartes(Card T[52]);
int getcolor(Card c);
void afficheType(Card c);
void afficheCard(Card c);
void affichePile(Pile p);
void addcolumn(Card T[52],Pile zone1[8]);
Pile clonePile(Pile p);
void shufflePile(Pile *p);
void afficheZone1(Pile zone1[8]);
void afficheZone2et3(Card zone2[],Pile zone3[]);
void operation();
void MoveZone1To1(Pile zone1[],int from,int to,int nbrCard);
void MoveZone1To2(Pile  zone1[],Card zone2[],int from,int to);
int colonneZone3(Card c,Pile zone3[]);
void MoveZone1To3(Pile zone1[],Pile zone3[],int from);
void MoveZone2To1(Pile zone1[],Card zone2[],int from,int to);
void MoveZone2To3(Card zone2[],Pile zone3[],int from);
void MoveZone3To1(Pile zone1[],Pile zone3[],int from,int to);
void MoveZone3To2(Card zone2[],Pile zone3[],int from,int to);
int testJeu(Pile zone3[]);
#endif // FONCTION_H_INCLUDED
