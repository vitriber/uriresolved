#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

	char palavra[51], aux[51];
	strcpy(palavra, "");
	fgets(palavra,51,stdin);
	int i = 0, j =0, k = 0;


    while(!feof(stdin)){ //Enquanto entrada diferente de nulo
        palavra[strcspn(palavra, "\n")] = 0; //Retira \n da ultima posição Fgets
        if(strcmp(palavra, "") == 0){ //se entrada vazia
            printf("\n");
        }else{
            //Remove Espaços da palavra
            palavra[strcspn(palavra, "\n")] = 0; //Retira \n da ultima posição Fgets
            strcpy(aux, palavra); //Copia palavra pro auxiliar e depois zera a string Palavra
            strcpy(palavra, "");
            for(k =0; k <strlen(aux); k++){ //percorre vetor auxiliar se igual se diferente de espaço nao insere em palavra
                if (aux[k] != ' '){
                    palavra[j] = aux[k];
                    j++;
                }
            }
            palavra[j]='\0'; //adiciona \0 ao final da palavra
            //Ordena a String
            i = 0; j = 0;
            for(i = 0; palavra[i  ] ; i++ )
            {
                for(j = 0; j < i ; j++) //percorre a string
                {
                    if(  (palavra[i ]) <  (palavra[ j])) //compara os valores se menor troca de posição
                    {
                        palavra[ i ] ^= palavra[  j];
                        palavra[ j ] ^= palavra[ i];
                        palavra[ i ] ^= palavra[ j];
                    }
                }
            }
            i = 0; j = 1;
            //Remove os caracteres duplicados
            strcpy(aux, palavra); //Copia a string palavra pra aux novamente
            while(i < strlen(palavra)) { //percorre a string
                if(palavra[i] == aux[j] ) //se for igual string palavra recebe auxiliar
                    palavra[i] = aux[j];
                else {
                    palavra[i+1] = aux[j]; //se nao posição a frente recebe auxiliar
                    i++;
                }
                j++;
            }
            i = 0; j = 0;
            //Procura as sequencias e printa na tela
            while(i < strlen(palavra)){ //percorre a string
                printf("%c:", palavra[i]); //printa a primeira letra da sequencia
                while(palavra[i] + 1 == palavra[i + 1]){ //enquanto palavra[i] + 1 for igual a proxima palavra [i + 1]
                    i++; //adciona i++
                }
                if(i == strlen(palavra) - 1){ //se for a ultima posição do vetor
                printf("%c", palavra[i]); //printa somente a letra
                }else{
                    printf("%c, ", palavra[i]); //se nao printa a letra com a virgula pra proxima sequencia
                }
                i++; //procurar sequencia a partir do proximo
            }
        }
        fgets(palavra,51,stdin); //le palavra novamente
        int i = 0, j =0, k = 0;
    }
	return 0;
}
