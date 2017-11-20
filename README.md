# Cifra de Cesar
A cifra de césar é uma das mais antigas criptografias conhecidas, sido utilizada por Júlio César, que viveu nos anos de 100 a.C a 44 d.C. Hoje, é considerada um tipo de criptografia muito ultrapassada e fácil de ser quebrada.

Por utilziar um algoritmo muito simples, pode ser utilizada como instrumento de aprendizado para quem está começando tanto na área de Programção como de Segurança. O arquivo Tutorial01.pdf é um guia que propõe um desafio envolvendo a Cifra de César. Caso queira se aventurar, baixe e siga as instruções contidas no arquivo "Tutorial 01 - Criptografia [Computação].pdf" neste diretório.


# INSTRUÇÕES DE USO:


-	Insira a chave(numeros de -22 a 22)

-	Insira palavra por palavra(caracteres especiais serão desconsiderados), depois precione ENTER

- Ao terminar de inserar todas as palavras, pressione CTRL+C para encerrar o programa

- A mensagem criptografada será gravada em um arquivo cifra.txt no diretório do programa


# FUNÇÕES CRIADAS:

```markdown
Função: VerificaTipo("Caractere")

Descrição: Verifica se o caractere é um número, letra minúscula, letra maiúscila ou caractere especial.
```

```markdown
Função: Cifrar("Caractere", "Chave (-22 a 22)")

Descrição: Cifra o caractere utilizando a cifra de César. Apenas funciona com com numeros e letras sem caracteres especiais, respeitando a tabela ASCII.
```

```markdown
Função: CifraDeCesar("Palavra a ser criptografada", "Chave (-22 a 22)")

Descrição: Chama a função "Cifrar" várias vezes, criptografando uma palavra.
```

```markdown
Função: ColetaChave("Chave (-22 a 22)")

Descrição: Coleta a chave inserida pelo usuário.
```

```markdown
Função: Criptografa("Arquivo", "Chave (-22 a 22)")

Descrição: Coleta a palavra a ser criptografada, dps criptografa, imprime e a grava em um arquivo.  
```

```markdown
Função: main()

Descrição: Como o nome sugere, é a função principal. Ela é a primeira a ser chamada quando se inicia o algoritimo, e é responsável por chamar todas as outras funções.
```

# BIBLIOTECAS UTILIZADAS:

Biblioteca    | Funções
------------- | -------------
stdio.h       | printf, scanf, fopen, fprintf, fclose
stdlib.h      | system
string.h      | strlen
