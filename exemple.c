#include <string.h> // strlen, strcat
#include <stdio.h>	// fopen, fgets, fclose, printf
#include <assert.h> // assert
#include <stdlib.h> // calloc, realloc, free

// le fichier crazy.cfg doit �tre dans le m�me dossier que votre .c
const char *const FILE_NAME = "crazy.cfg";

// La fonction qui suit illustre la lecture d'un fichier texte bloc par bloc.
// La variable buffer stocke les blocs lus l'un � la suite de l'autre.
//
// La taille des blocs est insuffisante pour pouvoir lire une ligne du
// fichier en un unique fgets.
//
// Quelque soit la taille choisie, ce cas de figure peut arriver avec le
// fichier crazy.cfg car la ligne d�crivant les animaux peut �tre d'une
// longueur quelconque.

static void byBlock()
{
	FILE *f = fopen(FILE_NAME, "r");
	if (f == NULL)
	{
		printf("fichier non accessible\n");
		return;
	}
	enum
	{
		BUFFER_SIZE = 10
	};
	char buffer[BUFFER_SIZE];
	char *s = fgets(buffer, BUFFER_SIZE, f);
	while (s != NULL)
	{
		size_t taille = strlen(buffer);
		assert(taille != 0);
		if (buffer[taille - 1] == '\n')
		{
			// La fin de ligne a �t� lue,
			// Elle peut �tre facilement retir�e du buffer
			buffer[taille - 1] = '\0';
			// Mais la cha�ne r�sultante peut �tre vide
			if (taille > 1)
				printf("'%s'", buffer);
			printf("\n");
		}
		else
		{
			// La fin de ligne n'a pas �t� lue
			printf("'%s'", buffer);
		}
		s = fgets(buffer, BUFFER_SIZE, f);
	}
	printf("\n");
	fclose(f);
}

// Si vous voulez collecter toute une ligne dans une unique variable
// il faut employer l'allocation dynamique (malloc et realloc)
// associ�e aux fonctions telle que strcat (concat�nation de cha�nes).
//
// C'est ce qu'illustre la fonction suivante.

// Quelques r�glages sp�cifiques � Visual...
// 4996 strcat est unsafe, on le sait et on s'en pr�muni, ce n'est pas grave.
#pragma warning(disable : 4996)
// 6308 realloc peut retourner NULL s'il n'y a pas assez de m�moire disponible
// 28183 strcat ne veut pas de NULL en premier argument
// on ignore ces deux derni�res erreurs potentielles, ce n'est pas bien
#pragma warning(disable : 6308 28183)

static void withConcatenation()
{
	FILE *f = fopen(FILE_NAME, "r");
	if (f == NULL)
	{
		printf("fichier non accessible\n");
		return;
	}
	enum
	{
		BUFFER_SIZE = 10
	};
	char buffer[BUFFER_SIZE];
	char *line = (char *)calloc(1, 1);
	char *s = fgets(buffer, BUFFER_SIZE, f);
	while (s != NULL)
	{
		size_t taille = strlen(buffer);
		assert(taille != 0);
		if (buffer[taille - 1] == '\n')
		{
			// La fin de ligne a �t� lue,
			// Elle peut �tre facilement retir�e du buffer
			buffer[taille - 1] = '\0';
			// Mais la cha�ne r�sultante peut �tre vide
			if (taille > 1)
			{
				line = (char *)realloc(line, strlen(line) + taille);
				strcat(line, buffer);
			}
			printf("'%s'\n", line);
			line[0] = '\0';
		}
		else
		{
			// La fin de ligne n'a pas �t� lue
			line = (char *)realloc(line, strlen(line) + taille + 1);
			strcat(line, buffer);
		}
		s = fgets(buffer, BUFFER_SIZE, f);
	}
	// si le fichier ne termine pas par une ligne vide, on affiche le contenu collect�
	if (strlen(line) != 0)
		printf("'%s'\n", line);
	free(line);
	fclose(f);
}

// Ce programme illustre comment les param�tres re�us sur la ligne de commande
// peuvent �tre r�cup�r�s un � un.
int main(int argc, const char *argv[])
{
	printf("%d parametre(s) recu(s) sur la ligne de commande\n", argc - 1);
	for (int i = 1; i < argc; ++i)
		printf("%s\n", argv[i]);
	printf("\n");

	byBlock();
	withConcatenation();
}