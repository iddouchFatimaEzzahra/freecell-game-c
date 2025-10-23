#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define MAX_CARDS 52
#define MAX_CELLS 16
#include<fonction.h>

Pile empiler(Pile p, Card c) {
Pile pile=(element*)malloc(sizeof(element));
pile->card=c;
pile->next=p;
return pile;
}
Card depilerCard(Pile *p) {
    Card c;
    Pile tmp;
    c = (*p)->card;
    tmp = (*p)->next;
    free(*p);
    *p = tmp;
    return c;
}
Pile  depiler(Pile p){
Pile tmp=p;
if(p!=NULL){
    p=p->next;
    free(tmp);
}return p;
}
//la longueur de la pile
int longueur(Pile p){
int lg=0;
while(p!=NULL){
    lg++;
    p=p->next;
}return lg;
}
void Color(int ctext,int cfond){
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,cfond*16+ctext);
}
void remplirTableCartes(Card T[52]){
    int i;Card c;
    for (i = 0; i < 13; i++) {
        c.value = i+1;
        c.type = 'C';
        T[i] = c;
        c.value = i+1;
        c.type = 'P';
        T[i + 13] = c;
        c.value = i+1;
        c.type = 'H';
        T[i + 26] = c;
        c.value = i+1;
        c.type = 'T';
        T[i + 39] = c;
    }
}
int getcolor(Card c){//red=1 - black=0
if(c.type=='H'|| c.type=='C'){return 1;
}
return 0;
}
void afficheType(Card c){
if(c.type=='H')
    printf("%c> ",3);
else if(c.type=='C')
    printf("%c> ",4);
else if(c.type=='T')
    printf("%c> ",5);
else
    printf("%c> ",6);
}
void afficheCard(Card c){
if(getcolor(c)==1)
    Color(4,15);
else
    Color(0,15);
if(c.value==1){
    printf("<As,");
    afficheType(c);}
else if(c.value==11){
    printf("<J ,");
    afficheType(c);}
else if(c.value==12){
    printf("<Q ,");
    afficheType(c);}
else if(c.value==13){
    printf("<K ,");
    afficheType(c);}
else if(c.value==10){
    printf("<%d,",c.value);
    afficheType(c);}
else{
    printf("<%d ,",c.value);
    afficheType(c);}
}
//affiche pile
void affichePile(Pile p){
while(p!=NULL){
   afficheCard(p->card);
   printf("\n");
    p=p->next;
}
}
void addcolumn(Card T[52],Pile zone1[8]){
int i=51,j;
remplirTableCartes(T);

while(i>=24){
    for(j=0;j<4;j++,i--){
        zone1[j]=empiler(zone1[j],T[i]);
    }
}
while(i>=0){
    for(j=4;j<8;j++,i--){
        zone1[j]=empiler(zone1[j],T[i]);
    }
}
}
Pile clonePile(Pile p) {
    Pile clone = NULL;
    Pile tmp = p;
    while (tmp != NULL) {
        clone = empiler(clone, tmp->card);
        tmp = tmp->next;
    }
    return clone;
}
void shufflePile(Pile *p) {
    // Convertir la pile en tableau
    Card cards[MAX_CARDS];
    int i = 0, j;
    while (*p != NULL) {
        cards[i++] = depilerCard(p);
    }
    srand(time(NULL));
    for (j=i-1;j > 0; j--) {
        int k = rand() % (j + 1);
        // Échanger les éléments
        Card temp = cards[j];
        cards[j] = cards[k];
        cards[k] = temp;
    }
    for (j = i - 1; j >= 0; j--) {
        *p = empiler(*p, cards[j]);
    }
}
void afficheZone1(Pile zone1[8]) {
    Color(3, 0);
    printf("\t\t\t\t\t\t\tZone :1\n");
    int i,j,maxSize = 0;
    for (i=0;i<8;i++) {
        int currentSize = longueur(zone1[i]);
        if (currentSize > maxSize) {
            maxSize = currentSize;
        }
    }
   Pile tmpZone1[8];
    for ( i = 0; i < 8; i++) {
        tmpZone1[i] = clonePile(zone1[i]);
    }
    Card matrix[52][8];
    Pile tmp;
    for (j = 0; j < 8; j++) {
            Color(7, 0);
        printf(" col-%d |\t", j);
        tmp = tmpZone1[j];
        i=0;
        while (tmp != NULL) {
            matrix[i][j] = tmp->card;
            tmp=depiler(tmp);
            i++;
        }

    }
    for (j=0;j<8;j++){
            tmp = tmpZone1[j];
    if(maxSize>longueur(tmp)){
               for(int k=longueur(tmp);k<maxSize;k++){
                matrix[k][j].value = 0;
               }
            }}
    // Afficher the matrix
    printf("\n");
    for (int i = 0; i < maxSize; i++){
        for ( int j = 0; j < 8; j++){
            if (matrix[i][j].value <= 0 || (matrix[i][j].type !='C' && matrix[i][j].type !='H' && matrix[i][j].type !='T' && matrix[i][j].type !='P')){
                printf("        \t");
            } else {
                afficheCard(matrix[i][j]);
                printf(" \t");
            }
        }
        printf("\n");
    }
}
void afficheZone2et3(Card zone2[],Pile zone3[]){
Color(3,0);printf("\tZone:2\t\t\t\t");
Color(3,0);printf("\t\t\t\tZone:3");printf("\n");
int j;
for(j=0;j<4;j++){
    Color(15,0);printf("col-%d|\t",j);
    }
     printf("\t\t\t\t");

    for (j = 0; j < 4; j++) {
        Color(15, 0); printf("col-%d|\t", j);
    }
    printf("\n");

   for(j=0;j<4;j++){
    Card tmp=zone2[j];
    if(tmp.value<=0 ||(tmp.type !='C' && tmp.type !='H' && tmp.type !='T' && tmp.type !='P')){
        Color(0,15);
        printf("<-,-> \t");
    }
    else{
    afficheCard(tmp);printf("\t");
    }
}  printf("\t\t\t\t");
    for(j=0;j<4;j++){
    Pile tmp=zone3[j];
    if (j == 0 && tmp == NULL) {
            Color(4, 15);
            printf("<-,%c> \t", 3);
        } else if (j == 1 && tmp == NULL) {
            Color(4, 15);
            printf("<-,%c> \t", 4);
        } else if (j == 2 && tmp == NULL) {
            Color(0, 15);
            printf("<-,%c> \t", 6);
        } else if (j == 3 && tmp == NULL) {
            Color(0, 15);
            printf("<-,%c> \t", 5);
        } else {
            afficheCard(tmp->card);
            printf("\t");
        }
}
}
void operation(){
    Color(15,2);
    printf("       ---------les operations de freecell--------\n");
    printf("       | 1=>deplacer une carte du zone1 au zone1 |\n");
    printf("       | 2=>deplacer une carte du zone1 au zone2 |\n");
    printf("       | 3=>deplacer une carte du zone1 au zone3 |\n");
    printf("       | 4=>deplacer une carte du zone2 au zone1 |\n");
    printf("       | 5=>deplacer une carte du zone2 au zone3 |\n");
    printf("       | 6=>deplacer une carte du zone3 au zone1 |\n");
    printf("       | 7=>deplacer une carte du zone3 au zone2 |\n");
    printf("       | 8=>Quitter le jeux                      |\n");
    printf("       -------------------------------------------\n");
}
void MoveZone1To1(Pile zone1[],int from,int to,int nbrCard){

    Pile tmpFrom=zone1[from];
    Pile tmpTo=zone1[to];
// Vérifier si les indices source et destination sont dans une plage valide
 if (from < 0 || from >= 8 || to < 0 || to >= 8) {
        return ;
    }
// Vérifier si la pile source n'est pas vide
 if (tmpFrom == NULL) {return ;
    }
 // Vérifier si le nombre de cartes à déplacer est dans une plage valide
 if (nbrCard <= 0 || nbrCard >longueur(tmpFrom)) {
       return ;
    }
// Pile temporaire pour contenir les cartes sélectionnées
    Pile p=NULL;
// Déplacer le nombre spécifié de cartes de la source vers la pile temporaire
    int i;
        for (i=0;i<nbrCard;i++){
             p= empiler(p,depilerCard(&tmpFrom));
             }
// Vérifier si la pile de destination est vide ou si la carte supérieure autorise le déplacement
    if ((tmpTo == NULL) || (tmpTo != NULL && tmpTo->card.value==(p->card.value + 1) && getcolor(tmpTo->card) != getcolor(p->card))) {
           // Déplacer les cartes de la pile temporaire vers la pile de destination
            while(p != NULL) {
                tmpTo = empiler(tmpTo,depilerCard(&p));
            }
            // Mettre à jour les piles source et destination dans le tableau zone1
            zone1[to]=tmpTo;
            zone1[from]=tmpFrom;
     } else {
        return ;
     }
}
void MoveZone1To2(Pile zone1[],Card zone2[],int from,int to){
Pile tmpfrom=zone1[from];
Card tmpto=zone2[to];
if (from < 0 || from >= 8 || to < 0 || to >= 4) {
        return ;
    }
if (tmpfrom == NULL) {
        return ;
    }
// Vérifier si la carte de destination dans zone2 est vide
if(tmpto.value==0){
     // Déplacer la carte supérieure de la pile source vers la carte de destination dans zone2
    tmpto=depilerCard(&tmpfrom);
    zone2[to]=tmpto;
    zone1[from]=tmpfrom;
}
else{
    return ;
}
}
// Fonction qui détermine la colonne de destination dans zone3 en fonction du type de carte
int colonneZone3(Card c,Pile zone3[]){
 if(c.type=='H'){
    return 0;
  }
  else if(c.type=='C'){
    return 1;
  }
  else if(c.type=='P'){
    return 2;
  }
  else{
    return 3;
  }
}
void MoveZone1To3(Pile zone1[],Pile zone3[],int from){
    Pile tmpfrom = zone1[from];
    int to=colonneZone3(tmpfrom->card,zone3);
    Pile tmpTo=zone3[to];
    if (tmpfrom==NULL){
        return ;
    }
    // Vérifier si la colonne de destination dans zone3 est vide ou respecte les règles
    if(tmpfrom!=NULL && tmpTo!=NULL && tmpTo->card.value+1 == tmpfrom->card.value){
        tmpTo = empiler(tmpTo, depilerCard(&tmpfrom));
        zone1[from] = tmpfrom;
        zone3[to] = tmpTo;
        return ;
    }
    else if(tmpfrom!=NULL && tmpTo== NULL && tmpfrom->card.value==1){
       // Si la colonne de destination est vide et la carte de la pile source est un As, déplacer la carte
       tmpTo = empiler(tmpTo, depilerCard(&tmpfrom));
       zone1[from] = tmpfrom;
        zone3[to] = tmpTo;
    }
    else {
       return ;
    }
}
void MoveZone2To1(Pile zone1[],Card zone2[],int from,int to){
Pile tmpto=zone1[to];
Card tmpfrom=zone2[from];
    if (from < 0 || from >= 4 && to<0 ||to>=8) {
        return ;
    }
    if (tmpfrom.value==0) {
       return ;
    }
    if ((tmpto == NULL) || (tmpto != NULL && tmpto->card.value==(tmpfrom.value + 1) && getcolor(tmpto->card) != getcolor(tmpfrom))) {
        tmpto = empiler(tmpto,tmpfrom);
        zone2[from].value =0;
        zone1[to]=tmpto;
    } else {
        return ;
    }
}
void MoveZone2To3(Card zone2[],Pile zone3[],int from){
    Card tmpfrom = zone2[from];
    int to=colonneZone3(tmpfrom,zone3);
    Pile tmpTo=zone3[to];
    if (tmpfrom.value==0) {
        return ;
    }
    if(tmpfrom.value!=0 && longueur(tmpTo) > 0 && tmpTo->card.value+1 == tmpfrom.value){
        tmpTo = empiler(tmpTo,tmpfrom);
        zone2[from].value =0;
        zone3[to] = tmpTo;
        return ;
    }
    else if(tmpfrom.value!=0 && longueur(tmpTo) == 0 && tmpfrom.value==1){
       tmpTo = empiler(tmpTo,tmpfrom);
       zone2[from].value = 0;
        zone3[to] = tmpTo;
    }
    else {
       return ;
    }
}
void MoveZone3To1(Pile zone1[],Pile zone3[],int from,int to){
    Pile tmpto = zone1[to];
    Pile tmpfrom=zone3[from];
    if (from < 0 || from >= 4 && to<0 ||to>=8) {
        return ;
    }
    if (tmpfrom==NULL) {
        return ;
    }
     if ((tmpto == NULL) || (tmpto != NULL && tmpto->card.value==(tmpfrom->card.value + 1) && getcolor(tmpto->card) != getcolor(tmpfrom->card))) {
        tmpto = empiler(tmpto,depilerCard(&tmpfrom));
        zone1[to]=tmpto;
        zone3[from]=tmpfrom;
    } else {
        return ;
    }
}
void MoveZone3To2(Card zone2[],Pile zone3[],int from,int to){
    Card tmpto = zone2[to];
    Pile tmpfrom=zone3[from];
     if (from < 0 || from >= 4 && to<0 || to>=4) {
        return ;
    }
    if (tmpfrom==NULL ) {
        return ;
    }
    if(tmpto.value==0){
    tmpto=depilerCard(&tmpfrom);
    zone2[to]=tmpto;
    zone3[from]=tmpfrom;
    }
   else{
    return ;
   }
}
int testJeu(Pile zone3[]){
    int i,countZone3 = 0;
    // Vérifier si zone3 a toutes les cartes avec la valeur 13 au sommet
    for (i=0;i<4;i++){
        if (zone3[i] != NULL && zone3[i]->card.value == 13) {
            countZone3++;
        }
        else{
            break;
        }
    }// Si toutes les conditions sont remplies, le joueur a gagné
    if (countZone3==4){
        return 1;  // Gagné
    }
    return 0;  // Pas encore gagné
}
