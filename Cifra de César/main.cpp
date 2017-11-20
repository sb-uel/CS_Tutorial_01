// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defines
#define CHAVE_MIN		-22
#define CHAVE_MAX		22

// Variáveis globais
enum tipo {
    numero = 0,
    minusculo = 1,
    maiusculo = 2
};
char zero = '0', nove = '9', a = 'a', A = 'A', z = 'z', Z = 'Z';

int VerificaTipo(unsigned char caractere)
{
	if (caractere >= zero && caractere <= nove)
		return numero;
	else if (caractere >= a && caractere <= z)
		return minusculo;
	else if (caractere >= A && caractere <= Z)
		return maiusculo;

	return -1; // caractere especial
}

void Cifrar(unsigned char* caractere, int chave)
{
	int delta = chave;
	switch (VerificaTipo(*caractere))
	{
	case numero:
		while (*caractere + delta > nove)
			delta = zero + delta - nove - 1;

		while (*caractere + delta < zero)
			delta = nove + delta - zero + 1;
		break;
	case minusculo:
		while (*caractere + delta > z)
			delta = a + delta - z - 1;

		while (*caractere + delta < a)
			delta = z + delta - a + 1;
		break;
	case maiusculo:
		while (*caractere + delta > Z)
			delta = A + delta - Z - 1;

		while (*caractere + delta < A)
			delta = Z + delta - A + 1;
		break;
	default:
		delta = 0;
		break;
	}
	*caractere = *caractere + delta;
}

char* CifraDeCesar(const char* texto, int chave)
{
	int tamanho = strlen(texto);
	unsigned char* nTexto = new unsigned char[tamanho + 1];
	for (int i = 0; i < tamanho; i++)
	{
		unsigned char caractere = texto[i];
		Cifrar(&caractere, chave);
		nTexto[i] = caractere;
	}
	nTexto[tamanho] = 0;
	return (char*)nTexto;
}


void ColetaChave(int &chave)
{
	do
	{
		printf("Insira a chave: ");
		scanf("%d", &chave);

		if (chave < CHAVE_MIN || chave > CHAVE_MAX) {
			printf("Chave invalida. Tente novamente\n");
			continue;
		}
		break;
	} while (1);
}

void Criptografa(const char* cArquivo, int chave)
{
	char palavra[50];
	FILE* arquivo;

	arquivo = fopen(cArquivo, "a");;
	printf("Insira a palavra: ");
	scanf("%s", palavra);
	printf("Criptografada: %s\n", CifraDeCesar(palavra, chave));
	fprintf(arquivo, " %s ", CifraDeCesar(palavra, chave));
	fclose(arquivo);
}

//Função Principal
int main()
{
	int chave = -1;

	system("color fc"); // mudar cor do cmd
	printf("\
Criptografia - Cifra de Cesar \n\n\
Como utilizar: \n\
1- Insira a chave(numeros de %d a %d) \n\
2- Insira palavra por palavra(caracteres especiais serão desconsiderados), depois precione ENTER\n\
3- Ao terminar de inserar todas as palavras, pressione CTRL+C para encerrar o programa\n\
4- A mensagem criptografada será gravada em um arquivo cifra.txt no diretório do programa\n",
CHAVE_MIN, CHAVE_MAX);

	ColetaChave(chave);

	while (1)
		Criptografa("cifra.txt", chave);

	return 0;
}
