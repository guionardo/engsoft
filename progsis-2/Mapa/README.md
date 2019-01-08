# MAPA da disciplina Programação de Sistemas 1

## Enunciado

A linguagem Java pode ser utilizada para desenvolvimento de diversos tipos de software: webservices, aplicações para dispositivos móveis, aplicações web e desktop, aplicações empresariais, jogos, entre outras.
Este MAPA irá permiti-lo utilizar a linguagem Java para a programação de um tanque robô em um jogo chamado Robocode (veja a Figura 1).
O Robocode é um jogo de programação, de código aberto, cujo objetivo é desenvolver um tanque robô para batalhar contra outros tanques. Veja o jogo na Figura 2.

![Figura 1- Robocode (Fonte: http://robocode.sourceforge.net/)](https://github.com/guionardo/progsis-2/raw/master/Mapa/QUE_46521_168213_1.png)

![Figura 2 - Batalha entre um robô programado e o robô Crazy de exemplo do jogo.](https://github.com/guionardo/progsis-2/raw/master/Mapa/QUE_46521_168213_2.png)

Para este MAPA, pede-se:

* [x] 1. Construa a classe para seu robô estendendo a classe Robot disponível no pacote robocode.
* [x] 2. Altere a cor do seu robô.
* [x] 3. Altere a cor da bala.
* [x] 4. Sobrescreva o método run() de Robot para codificar a estratégia de jogo do seu robô.
* [x] 5. Crie alguns métodos apelidos para métodos herdados para facilitar a leitura do seu código.
  * [x] a. virarPraDireita()  – deve ser apelido para turnRight(90)
  * [x] b. virarPraEsquerda()  – deve ser apelido para turnLeft(90)
  * [x] c. virarPraTras() – deve ser apelido para turnLeft(180) ou turnRight(180), escolha.
  * [x] d. andarPraFrente(double quantosPixels)  – deve ser apelido para ahead(double quantosPixels).
  * [x] e. andarPraTras(double quantosPixels)  – deve ser apelido para back(double quantosPixels)
  * [x] f. atirar(double energiaDaBala) – deve ser apelido para fire(double power)
  * [x] g. parar() – deve ser apelido para stop()
* [ ] 6. Faça chamadas dos métodos apelidos que foram criados para programar a estratégia do seu robô. Também podem ser utilizados outros métodos herdados da superclasse.
* [x] 7. Utilize pelo menos uma vez a instrução de decisão if na sua estratégia.
* [x] 8. Utilize pelo menos uma vez uma constante definida na classe Rules. Exemplos: Rules.MIN_BULLET_POWER, Rules.MAX_BULLET_POWER ou qualquer outra.
* [ ] 9. Sobrescreva os métodos
  * [x] a. onScannedRobot
  * [x] b. onHitByBullet
  * [x] c. onHitWall
  * [x] d. onHitRobot
  * [x] e. onWin.
* [x] 10. Coloque seu robô em uma batalha contra algum outro (ou contra ele mesmo). Seu robô não precisa ganhar a batalha, mas precisa participar do jogo andando, virando, vasculhando o outro robô, atirando e desencalhando caso bata em alguma parede. Seu robô será testado em uma batalha na correção deste Mapa.

Dois vídeos complementares a este material foram disponibilizados no Youtube para mostrá-lo como configurar o Robocode no Netbeans:

* Parte 1 - <https://www.youtube.com/watch?v=0y4FSKrPg4c>
* Parte 2 - <https://www.youtube.com/watch?v=lDU6ZyyMQ6M>

O resultado dessa atividade deve ser um pacote Java contendo apenas uma classe robô dentro e deverá ser entregue zipado. Nomeie a classe criada com o seu nome, exemplo: CarlosNantesRobo.java. Siga os dois tutoriais acima disponibilizados pelo professor para ter um exemplo de como iniciar a atividade. Atingirá a nota máxima do trabalho o aluno que concluir o que se pede nos 10 itens.

Utilize alguns dos links abaixo ou pesquise outros para aprender detalhes de como codificar o seu robô:

* Manual de Instruções do Robocode (das páginas 11 à 27) <http://www.ufjf.br/jairo_souza/files/2015/11/Robocode-Manual-de-Instruc%CC%A7o%CC%83es.pdf>
* <https://pt.slideshare.net/gscheibel/batalhas-com-robocode>
* <https://player.slideplayer.com.br/11/3016561/#>
* <https://slideplayer.com.br/slide/3649323/>
* <http://www.ufjf.br/jairo_souza/files/2015/11/RoboCode.pdf>
* <https://www.youtube.com/watch?v=iYZ7lBwV-OQ>
* <https://www.youtube.com/watch?v=5eMe-ZZucsA>
* <https://www.youtube.com/watch?v=KGYL7WRlYiA>
* <https://www.youtube.com/watch?v=IhmrPfkRnR0>
* <https://www.youtube.com/watch?v=CU3qLtZ72PA>
* <https://www.youtube.com/watch?v=enuFs1WFiB4>
* <https://www.youtube.com/watch?v=CZYmfo5DYxo>
* <http://www.robocodebrasil.com.br/mini-curso.php>
* <http://robocode.sourceforge.net/docs/robocode/>
* <http://robocode.sourceforge.net/>
* <http://robowiki.net/wiki/Robocode/Game_Physics>
