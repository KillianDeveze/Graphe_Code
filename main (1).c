#include<stdio.h>
#include<conio.h>
#define infinie 9999
#define MAX 10

void dijkstra(int mAdjacence[MAX][MAX],int nbSommets,int sommetDepart);

int main()
{
    int mAdjacence[MAX][MAX],nX,j,nbSommets,sommetDepart;
    printf("Entrez le nombre de sommets:");
    scanf("%d",&nbSommets);
    printf("\nEntrez la matrice d adjacence:\n");
    //On stock la matrice entrée dans mAjacence
    for(nX=0;nX<nbSommets;nX++)
        for(j=0;j<nbSommets;j++)
            scanf("%d",&mAdjacence[nX][j]);

    printf("\nEntrez le sommet de depart:");
    scanf("%d",&sommetDepart);
    dijkstra(mAdjacence,nbSommets,sommetDepart);
    return 0;
}

void dijkstra(int mAdjacence[MAX][MAX],int nbSommets,int sommetDepart)
{

    int cout[MAX][MAX];//Matrice contenant le cout de chaque sommet
    int distance[MAX];//Tableau contenant la distance entre le sommet de départ et le sommet associé
    int precedent[MAX];//Tableau contenant les sommet ayant servie à atteindre un sommet
    int visite[MAX];//Tableau contenant les sommet visité
    int count;
    int DistanceMin;
    int SommetSuivant;
    int i;
    int j;
    //Cree la matrice de cout
    for(i=0;i<nbSommets;i++)
        for(j=0;j<nbSommets;j++)
            if(mAdjacence[i][j]==0)
                cout[i][j]=infinie;
            else
                cout[i][j]=mAdjacence[i][j];

    //Initialise la matrice de Distance, le tableau de précédent et le tableau de sommets visité
    for(i=0;i<nbSommets;i++)
    {
        distance[i]=cout[sommetDepart][i];
        precedent[i]=sommetDepart;
         visite[i]=0;
    }

    distance[sommetDepart]=0;//Le sommet de depart à une distance de 0 de lui meme
    visite[sommetDepart]=1;//Et il est obligatoirement déjà visité
    count=1;

    while(count<nbSommets-1)
    {
        DistanceMin=infinie;//Initialement ,on considère le plus cours chemin comme étant infinie

        //Sommet suivant devient égale au sommet le plus proche
        for(i=0;i<nbSommets;i++)
            if(distance[i]<DistanceMin&&! visite[i])//Si le sommet n'a pas encore été visité et que il est à une distance plus petit que la distance précédement trouvé
            {
                DistanceMin=distance[i];
                SommetSuivant=i;
            }

            //Verifie si un chemin plus cours existe en passant par SommetSuivant
             visite[SommetSuivant]=1;
            for(i=0;i<nbSommets;i++){
                if(! visite[i]){
                    if(DistanceMin+cout[SommetSuivant][i]<distance[i])
                    {
                        distance[i]=DistanceMin+cout[SommetSuivant][i]; //La distance vers ce point devient désormais le chemin plus court qui à été trouvé
                        precedent[i]=SommetSuivant;// On enregistre le sommet qui a servi a l'atteindre dans precedant
                    }
                }
            }
        count++;
    }

    //Affichage de distance jusqu'à chaque node ainsi que le trajet utilisé
    for(i=0;i<nbSommets;i++)
        if(i!=sommetDepart)
        {
            printf("\nDistance of node%d=%d",i,distance[i]);
            printf("\nPath=%d",i);

            j=i;
            do
            {
                j=precedent[j];
                printf("<-%d",j);
            }while(j!=sommetDepart);
    }
}
