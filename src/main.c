#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define MAX_CARDS 52
#define MAX_CELLS 16
#include<fonction.h>

int main()
{   Color(2,0);
    int start;
        printf("|=======================================================================================================|\n");
	printf("|                                                                                                       |\n");
	printf("|\t\t****************    ****************    ****************    ****************\t\t|\n|\t\t****************    ****************    ****************    ****************\t\t|\n");
	printf("|\t\t***                 ***          ***    ***                 ***             \t\t|\n|\t\t***                 ***          ***    ***                 ***             \t\t|\n");
	printf("|\t\t****************    ****************    ****************    ****************\t\t|\n|\t\t****************    ****************    ****************    ****************\t\t|\n");
	printf("|\t\t***                 ******              ***                 ***             \t\t|\n|\t\t***                 ***   ***           ***                 ***             \t\t|\n");
	printf("|\t\t***                 ***       ***       ****************    ****************\t\t|\n|\t\t***                 ***          ***    ****************    ****************\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t****************    ****************    ***                 ***             \t\t|\n|\t\t****************    ****************    ***                 ***             \t\t|\n");
	printf("|\t\t***                 ***                 ***                 ***             \t\t|\n|\t\t***                 ***                 ***                 ***             \t\t|\n");
	printf("|\t\t***                 ****************    ***                 ***             \t\t|\n|\t\t***                 ****************    ***                 ***             \t\t|\n");
	printf("|\t\t***                 ***                 ***                 ***             \t\t|\n|\t\t***                 ***                 ***                 ***             \t\t|\n");
	printf("|\t\t****************    ****************    ****************    ****************\t\t|\n|\t\t****************    ****************    ****************    ****************\t\t|\n");
	printf("|                                                                                                       |\n");
	printf("|                                                                                                       |\n");
	printf("|                                                                                                       |\n");
	printf("|                                        -----------------------                                        |\n");
	printf("|                                        | START NEW GAME -> 1 |                                        |\n");
	printf("|                                        -----------------------                                        |\n");
	printf("|                                        | QUIT THE GAME  -> 0 |                                        |\n");
	printf("|                                        -----------------------                                        |\n");
	printf("|                                                                                                       |\n");
	printf("|======================================================================== BY: IDDOUCH FATIMA-EZZAHRA ===|\n");
	printf("-->");
	scanf("%d",&start);
	if(start==1){
    Card T[52];
    Pile zone1[8];
    Card zone2[4];
    Pile zone3[4];
    int i;
    int x,from,to,nbrCard;
    for (i=0;i<8;i++){
        zone1[i] = NULL;
    }
    for (i=0;i<4;i++){
        zone2[i].value = 0;
        zone3[i] = NULL;
    }
    addcolumn(T,zone1);

    for (i=0;i<8;i++){
        shufflePile(&zone1[i]);
    }
    int c=testJeu(zone3);
        while(c!=1){
        system("cls");
        system("Color 21");
        afficheZone2et3(zone2,zone3);
        printf("\n\n");
        afficheZone1(zone1);
        printf("\n");
        operation();
        printf("choisir une operation: ");
        scanf("%d", &x);
        if(x==1){
            printf("colonne de depart:");
            scanf("%d",&from);
            printf("colonne d'arriver: ");
            scanf("%d",&to);
            printf("nombre de carte: ");
            scanf("%d",&nbrCard);
            MoveZone1To1(zone1, from, to, nbrCard);
        }
        if(x==2){
            printf("colonne de depart: ");
            scanf("%d",&from);
            printf("colonne d'arriver: ");
            scanf("%d",&to);
            MoveZone1To2(zone1, zone2,from, to);
        }
        if(x==3){
            printf("colonne de depart: ");
            scanf("%d",&from);
            MoveZone1To3(zone1,zone3,from);
        }
        if(x==4){
            printf("colonne de depart: ");
            scanf("%d",&from);
            printf("colonne d'arriver: ");
            scanf("%d",&to);
            MoveZone2To1(zone1, zone2,from,to);
        }
        if(x==5){
            printf("colonne de depart: ");
            scanf("%d",&from);
            MoveZone2To3(zone2,zone3,from);
        }
        if(x==6){
            printf("colonne de depart: ");
            scanf("%d",&from);
            printf("colonne d'arriver: ");
            scanf("%d",&to);
           MoveZone3To1(zone1,zone3,from,to);
        }
        if(x==7){
            printf("colonne de depart: ");
            scanf("%d",&from);
            printf("colonne d'arriver: ");
            scanf("%d",&to);
            MoveZone3To2(zone2,zone3,from,to);
        }
        if(x==8){
        printf("------jeu terminer------");
          return;
        }
       c=testJeu(zone3);
     }
     if(c==1){
        printf("---------""Félicitations,vous avez gagné""---------");
     }
	 }
	else{
        system("cls");
		printf("\t\tBYE BYE!!");
		return 0;
	}
}
