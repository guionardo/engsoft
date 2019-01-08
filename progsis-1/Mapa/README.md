# MAPA da disciplina Programação de Sistemas 1

## Enunciado

A linguagem Java segue o paradigma de programação orientado a objetos, com isso a nossa programação baseia-se nesses conceitos. Para esta atividade, criaremos uma aplicação usando qualquer editor, mas o código deve ser executado em linha de comando, sem bibliotecas gráficas.

Você deve implementar um sistema de votação. O seu programa deve gerar 10.000 votos aleatórios entre 6 candidatos (1 a 6). O programa deve exibir quantos votos cada candidato teve e exibir, ao final, quem foi o vencedor e com quantos votos.

Para isso, seu trabalho precisa ter:

* Uma classe chamada Mapa, de onde o método main será executado.
* Um array de candidatos para armazenar o número de votos.
* A geração de 10.000 votos aleatórios, armazenando o voto para o candidato certo.
* Exibir a quantidade de votos de cada candidato.
* Exibir o candidato vencedor.

Exemplo de algumas chamadas do sistema:

![Exemplo de algumas chamadas do sistema](https://github.com/guionardo/progsis-1/raw/master/Mapa/QUE_46519_177459_1.png)

Para gerar números aleatórios, você pode usar os seguintes comandos:

```java
import java.util.Random; // no início
Random gerador = new Random(); // para gerar o objeto
variavel = gerador.nextInt(6);  // gera números de 0 a 5
```

Deixe seu programa para compilar e rodar com os seguintes comandos:

```
javac Mapa.java
java Mapa
```

Depois de finalizado, envie seu arquivo Mapa.java.

Um ótimo trabalho pra você!
