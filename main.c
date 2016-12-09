#include <stdio.h>

///////////////////////////////////
//      FONCTION VISUELJEU       //
//                               //
///////////////////////////////////


//on met ici en paramètre un tableau qui va nous servir à mettre les valeurs des cases pour ordi et joueur

void visuelJeu (int awale[12]){
    int i, j;
    
// on génère deux boucles qui vont nous afficher les valeurs du tableau
    
        for (j = 11; j > 5; j--) {
            printf("%d ",awale[j]);
    }
    
    printf("\n");
    
        for (i = 0; i <= 5; i++) {
            printf("%d ",awale[i]);
    
    }
}

///////////////////////////////////
//        FONCTION SCORE         //
//                               //
///////////////////////////////////

//on crée une fonction qui va nous permettre de comptabiliser les scores et les afficher

void score (int pointJoueur, int pointOrdi){
    int scoreJoueur = 0;
    int scoreOrdi = 0;
    
    //le score du joueur = son score actuel + les points gagnés
    
    scoreJoueur = scoreJoueur + pointJoueur;
    scoreOrdi = scoreOrdi + pointOrdi;
    
    //on affiche les scores
    
    printf("\nScore Minouche : %d\n", scoreJoueur);
    printf("\nScore Ordi : %d\n", scoreOrdi);
}


///////////////////////////////////
//  FONCTION DISTRIBUTIONJOUEUR  //
//                               //
///////////////////////////////////

//on crée une fonction qui va nous distribuer les billes dans le tableau du joueur

void distributionJoueur (int caseJoue, int nbBille, int awale[]){
    int i;
    int casesRestantes;
    int supplement;
    
    casesRestantes = caseJoue - 6;
    
    
//on défini ici le supplément c'est à dire le nombre de bille restante une fois les cases du joueur rempli
    
    supplement = awale[caseJoue] + nbBille - casesRestantes;
    
//on part de la case qu'il souhaite jouer, et on va jusqu'au nb de bille qu'il souhaite utiliser en incrémentant de 1

        for (i = caseJoue; i <= nbBille; i++) {
                        awale[i]++;
        }
    

//si on a une bille restante après que le joueur ai rempli toute ses cases il remporte cette bille
    
    if (supplement == 1) {
        score(1,0);
    }
    else {
        
/*si le nombre de bille restante après que le joueur ai joué est supérieur ou égal à 2 et inférieur à 6 alors l'ordi remporte la dernière bille*/
        
        if (supplement >= 2 && supplement < 6) {
            score(0,1);
        }
        
//sinon on distribue les billes à nouveau dans les cases du joueur
        
        else {
            distributionJoueur(1, supplement, awale);
        }
    }
    
    visuelJeu(awale);
    
    }


///////////////////////////////////
//   FONCTION DISTRIBUTIONORDI   //
//                               //
///////////////////////////////////

//on crée une fonction qui va nous distribuer les billes dans le tableau de l'ordinateur

void distributionOrdi (int caseJoue, int nbBille, int awale[]){
    int i;
    
//on part de la case qu'il souhaite jouer, et on va jusqu'au nb de bille qu'il souhaite utiliser en incrémentant de 1
    
        for (i = caseJoue; i <= nbBille; i--) {
            
            awale[i]++;
        }
    
    visuelJeu(awale);

    }

///////////////////////////////////
//  FONCTION FINDUJEU            //
//                               //
///////////////////////////////////

int findujeu(int awale[]){
    int i;
    int tableau0 = 0;

//on initialise deux variables qui vont nous permettre de faire la somme des éléments du tableau pour voir si on est à 0

    int sommeO = 0;
    int sommeJ = 0;
    
//on parcours les éléments du tableau de l'ordinateur et on additionne les valeurs dans somme0

        for (i = 11; i > 5; i--){
            sommeO += awale[i];
    }
    
//on parcours les éléments du tableau du joueur et on additionne les valeurs dans sommeJ

        for (i = 0; i <= 5; i++){
        sommeJ += awale[i];
    }
    
//si l'un des tableaux à l'ensemble de ses valeur à 0 alors tableau0 = 1
    
        if (sommeO == 0 || sommeJ == 0) {
        tableau0 = 1;
    }
    return tableau0;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////
//              MAIN             //
//                               //
///////////////////////////////////

int main(int argc, const char * argv[])
{

//initialisation du tableau

    int awale[12] = {4,4,4,4,4,4,4,4,4,4,4,4};
    int caseJoue = 0;
    int nbBille = 0;
    int tourdejeu = 0;
    
    visuelJeu(awale);
    printf("\n");
    
    do {
        
//si le reste de la division de tour de jeu est 0 alors le joueur joue
        
        if (tourdejeu%2==0){
            
//on demande à l'utilisateur de faire son choix

            printf("\nA VOTRE TOUR DE JOUER\n\n");
            printf("\nQuelle case souhaitez vous prendre ?\n");
            scanf("%d\n", &caseJoue);
            printf("Combien de bille souhaitez-vous prendre ?\n");
            scanf("%d", &nbBille);
            
//si le nb de bille entré par le joueur est inférieur à 3 on lui demande de refaire son choix
            
            if (nbBille < 3) {
                printf("Merci de refaire votre choix\n");
            }
            else{
                distributionJoueur(caseJoue,nbBille,awale);
                
//on incrémente la valeur de tourdejeu car en fonction de cela on saura qui doit jouer
                
                tourdejeu++;
                printf("\nFIN DU TOUR\n\n");
            }
        }
        
//sinon c'est le tour de l'ordi
        else {
            //Tour de l'ordinateur
            printf("\nL'ordinateur Joue\n\n");
            tourdejeu++;
            printf("\nFIN DU TOUR de l'0rdinateur\n\n");
        }

//on effectue l'action temps un des joueurs n'a plus de bille

    } while(findujeu(awale)==0);
    return 0;
}
