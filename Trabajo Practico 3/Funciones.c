#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int validar_Entero(int* pEntero)
{
    int error=1;
    char aux_Entero[128];

    if(pEntero!=NULL)
    {

        fflush(stdin);
        gets(aux_Entero);


        for(int i=0; i<strlen(aux_Entero); i++)
        {
            *pEntero=atoi(aux_Entero);

            while(isalpha(aux_Entero[i]) != 0 || pEntero <= 0 || aux_Entero[i] == ' ' || aux_Entero[i] == ',' || aux_Entero[i] == '.')
            {
                printf("\nError, Reingrese el numero correctamente:\n> ");
                fflush(stdin);
                gets(aux_Entero);
                i=0;
                *pEntero = atoi(aux_Entero);
            }

        }
    }
    return error;
}

int validar_StringCaracteres(char* pString)
{
    int error=1;
    int valido=0;

    if(pString!=NULL)
    {
        fflush(stdin);
        scanf("%s", pString);

        while(!valido)
        {
            if(pString!=NULL)
            {
                if(strlen(pString)>128)
                {
                    valido=0;
                }
                else
                {
                    for(int i=0 ; pString[i]!='\0' && i<strlen(pString); i++)
                    {
                        if((pString[i]<'A' || pString[i]>'Z' ) && (pString[i]<'a' || pString[i]>'z' ))
                        {
                            valido=0;
                            break;
                        }
                        valido=1;
                    }
                }
                if(!valido)
                {
                    printf("\nError, Reingrese el texto correctamente:\n> ");
                    fflush(stdin);
                    scanf("%s", pString);
                }
            }
        }
        error=0;
    }
    return error;
}

