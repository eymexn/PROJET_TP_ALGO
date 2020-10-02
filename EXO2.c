#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* qst1 */
int Compresser(char src_path[50],char dst_path[50])
{
    FILE * fpt;
    fpt = fopen(src_path, "r");
    int Arr[80];
    int i = 0;

    while(!feof(fpt))
    {
        fscanf(fpt, "%i", &Arr[i]);
        if(Arr[i] != 0)
        {
            i++;
        }
    }
    fclose(fpt);

    int lenArr = i;
    int arrCmp[lenArr][2];
    arrCmp[0][0] = Arr[0];
    arrCmp[0][1] = 0;
    int indArr = 0;

    for(i=1; i<=lenArr; i++)
    {

        if(arrCmp[indArr][0] == Arr[i-1])
        {
            arrCmp[indArr][1] += 1;
        }
        else
        {
            indArr++;
            arrCmp[indArr][1] = 1;
            arrCmp[indArr][0] = Arr[i-1];
        }
        
    }



fpt = fopen(dst_path, "w");

for(i=0; i<= indArr; i++)
{
    fprintf(fpt, "%i %i\n", arrCmp[i][0], arrCmp[i][1]);

}

    fclose(fpt);

    return 0;
}




/* qst 3 */
int Decompresser(char src_path[50],char dst_path[50])
{
    FILE * fpt1;
    fpt1 = fopen(src_path, "r");

    FILE * fpt2;
    fpt2 = fopen(dst_path, "w");

    int a,b,i;

    while(!feof(fpt1))
    {
        fscanf(fpt1, "%i %i\n", &a, &b);
        for(i=0; i<b; i++)
        {
            fprintf(fpt2, "%i\n", a);
        }
        
        if(!feof(fpt1))
        {
            fprintf(fpt2, "%i\n", 0);
        }

    }

    fclose(fpt1);
    fclose(fpt2);

    return 0;

}



int main()
{

    /* deroulement qst1 */
    Compresser("F.txt", "G.txt");


    /* qst 2 */
    FILE * fpt = fopen("G.txt", "r");
    int lngSec, Sec, blnk, line, lngPos, Sec1;
    int tot[20];

    fscanf(fpt, "%i %i\n",&blnk , &lngSec);
    line = 1;
    tot[0]=lngSec;
    Sec1 = lngSec;

    while(!feof(fpt))
    {
        fscanf(fpt, "%i %i\n",&blnk , &Sec);
        line++;
        tot[line-1] = Sec + tot[line-2];

        if(Sec > lngSec)
        {
            lngSec = Sec;
            lngPos = line;
        }

    }
    fclose(fpt);

    int pos;

    if(Sec1==lngSec)
    {
        pos = 1;
    }else
    {
        pos = tot[lngPos-2] + lngPos;
    }

    printf("\nla position de la plus longue sequence en F est: POS = %i.", pos);

    /* deroulement qst3 */
    Decompresser("G.txt", "H.txt");

    return 0;

}
