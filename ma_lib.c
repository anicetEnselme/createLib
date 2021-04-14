#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h> 
#include <stdbool.h>
#include <ctype.h>

int get_metrics(int pid)
{
	char buf[255];
char line_split[255][255]; //contenir chaque ligne du fichier
int pids[255];
int vss[255];
int uss[255];
int rss[255];
int j,k;
bool is_not_end = true;
FILE *fp = fopen("test2.txt", "r");
if (fp == NULL)
{
fprintf(stderr,
"Le fichier texte.txt n'a pas pu être ouvert\n");
return EXIT_FAILURE;
}
int l = 0;
while(is_not_end)
{
	if (fgets(buf, sizeof buf, fp) != NULL)
	{
		j = 0;
		k = 0;
		//printf("%s==========%d\n", buf, sizeof buf);
		for (int i = 0; buf[i]!='\0'; ++i)
		{
			if (buf[i] == '|')
			{
				//printf("Je suis vraiment fatigué bg\n");
				j++;
				k =0;
			}
			else if(isdigit(buf[i]))
			{
				//printf("Avant l'affectation, on a line[%d][%d]=%c\n",j,k,line_split[j][k]);
				//printf("Bah sinon affecte lui simplement la valeur non??\n");
				line_split[j][k] = buf[i];
			//	printf("Apres afectation on a line[%d][%d]=%c\n",j,k,line_split[j][k]);
				k++;
			}
			//printf("%c\n", buf[i]);
		}
		//printf("le premier élément est donc:%s, le sesond %s, le troisieme %s\n", line_split[0], line_split[1], line_split[2]);
		pids[l] = atoi(line_split[0]);
		vss[l] = atoi(line_split[1]);
		rss[l] = atoi(line_split[2]);
		uss[l] = atoi(line_split[3]);
		l++;
		
	}
	else if (ferror(fp))
	{
		fprintf(stderr, "Erreur lors de la lecture\n");
		return EXIT_FAILURE;
	}
	else
	{
		//fprintf(stderr, "Fin de fichier rencontrée\n");
		for (int i = 0; pids[i] != '\0' ; ++i)
		{
			//printf("pids dans le fichier:%d\n", pids[i]);
			if (pids[i] == pid)
			{
				printf("vss : %dkb rss : %dkb uss : %dkb\n",vss[i],rss[i],uss[i]);
			}
			
		}
		return EXIT_FAILURE;
	}
}

if (fclose(fp) == EOF)
{
	fprintf(stderr, "Erreur lors de la fermeture du flux\n");
	return EXIT_FAILURE;
}
return 0;
}

void print_num()
{
  	long int tab[1000000];
    for (int i = 0; i < sizeof(tab); ++i)
	{
		tab[i] = i;
	  //printf("Je suis la");
	  //sleep(10);
	}
}