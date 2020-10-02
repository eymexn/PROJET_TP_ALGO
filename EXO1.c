#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/* qst1 */
struct achat
{
    char nom_article[20];
    float montant;
    char date[10];


    /* pour qst3*/
    int mois;

}achat;




/* fonction qst2 */
struct achat remplir_list(int n)
{

        struct achat Achat;

        printf("\n-----------------------------------------------------------");
        printf("\nAchat n%i", n+1);
        printf("\nNom de Produit: ");
        scanf("%s", Achat.nom_article);
        printf("Prix: ");
        scanf("%f", &Achat.montant);
        printf("Date(JJ/MM/AAAA): ");
        scanf("%s", Achat.date);

    return Achat;
}


/* fonction qst 3 */
int sauv_infos(struct achat listA[20], struct achat listB[20], int num1, int num2)
{

    FILE * fptr1;
    fptr1 = fopen("FicheAchatAlger.txt", "w");

    for(int i=0; i<num1; i++)
    {
        fprintf(fptr1, "%s %.2f %s\n", listA[i].nom_article, listA[i].montant, listA[i].date);
    }
    fclose(fptr1);

    FILE * fptr2;
    fptr2 = fopen("FicheAchatBlida.txt", "w");

    for(int i=0; i<num2; i++)
    {
        fprintf(fptr2, "%s %.2f %s\n", listB[i].nom_article, listB[i].montant, listB[i].date);
    }
    fclose(fptr2);
    return 0;
}


/* fonction qst4 */
int dpns_mois(int achA, int achB)
{
    struct achat List_ach[20];
    const int achTOT = achB + achA;

    FILE * fp1;
    FILE * fp2;
    fp1 = fopen("FicheAchatAlger.txt", "r");
    fp2 = fopen("FicheAchatBlida.txt", "r");
    char blank[10];
    int i=0;

    while(!feof(fp2))
    {
        fscanf(fp2, "%s %f %s\n", List_ach[i].nom_article, &List_ach[i].montant, List_ach[i].date);
        strcpy(blank, List_ach[i].date);
        sprintf(blank, "%c%c", blank[3], blank[4]);
        List_ach[i].mois = atoi(blank);
        i++;
    }
    fclose(fp2);


    while(!feof(fp1))
    {
        fscanf(fp1, "%s %f %s\n", List_ach[i].nom_article, &List_ach[i].montant, List_ach[i].date);
        strcpy(blank, List_ach[i].date);
        sprintf(blank, "%c%c", blank[3], blank[4]);
        List_ach[i].mois = atoi(blank);
        i++;
    }
    fclose(fp1);

    float d[12]= {0,0,0,0,0,0,0,0,0,0,0,0};

    for(i=0; i < (achA + achB) ; i++)
    {
        d[ List_ach[i].mois - 1 ] += List_ach[i].montant;
    }


    char list_mois[12][20] = {"JANVIER","FEVRIER", "MARS", "AVRIL", "MAI", "JUIN", "JUILLET", "AOUT", "SEPTEMBRE", "OCTOBRE", "NOVEMBRE", "DECEMBRE"};
    printf("\n\n\nLES MOIS OU LES DEPENSES DEPASSENT 30000DA:");
    for(i=0; i <12 ; i++)
    {
        if(d[i]>=30000)
        {
            printf(" -%s", list_mois[i]);
        }
    }
    printf(".\n\n");

    return 0;
}


int main()
{
    /* suite qst2 */
    int achA;
    int achB;

    printf("LISTE D'ACHATS ALGER");
    printf("\nENTRER LE NBRE D'ARTICLES ACHETES: ");
    scanf("%i", &achA);

    struct achat ListAchatAlger[achA];

    for(int i=0; i<achA; i++)
    {
        ListAchatAlger[i] = remplir_list(i);
    }

    printf("\nLISTE D'ACHATS BLIDA");
    printf("\nENTRER LE NBRE D'ARTICLES ACHETES: ");
    scanf("%i", &achB);

    struct achat ListAchatBlida[achB];

    for(int i=0; i<achB; i++)
    {
        ListAchatBlida[i] = remplir_list(i);
    }
    /* fin qst2 */


    /* deroulement qst3 */
    sauv_infos(ListAchatAlger, ListAchatBlida, achA, achB);


    /* derpilement qst4 */
    dpns_mois(achA, achB);


    return 0;
}
