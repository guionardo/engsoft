/** 
 * Atividade MAPA Engenharia de Software - Programação de Sistemas 2
 * Aluno RA 1650466-5 Guionardo Furlan
 * Código desta atividade disponível em https://github.com/guionardo/progsis-2/tree/master/Mapa
 */
package unicesumar.progsis2;

import robocode.*;
import java.awt.Color;
import java.util.Random;

/**
 * 1. Construa a classe para seu robô estendendo a classe Robot disponível no
 * pacote robocode. GuionardoFurlan - a robot by Guionardo Furlan
 */
public class GuionardoFurlan extends Robot {
    private Random gerador = new Random();
    private int passos = 10;

    /**
     * run: Guionardo2's comportamento padrão 4. Sobrescrevendo o método run
     */
    public void run() {
        log("INIT GuionardoFurlan");
        // 2. Altere a cor do seu robô
        setBodyColor(Color.gray);
        // 3. Altere a cor da bala
        setBulletColor(Color.orange);

        float anguloCurva = 0;
        int modo = 0;

        while (true) {
            switch (modo) {
            case 0:
                // A cada 10 passos, muda a direção aleatoriamente
                if (passos > 0) {
                    passos--;
                } else {
                    turnLeft(gerador.nextFloat() * 360f - 180f);
                    passos = 10;
                    modo = 1;
                }
                turnGunRight(180);
                break;
            case 1:
                // Anda em curva, mudando o ângulo aleatoriamente a cada 10 passos
                if (passos > 0) {
                    passos--;
                } else {
                    anguloCurva = (gerador.nextFloat() * 60f - 30f);
                    passos = 10;
                    modo = 0;
                }
                turnRight(anguloCurva);
                break;
            }
            andarPraFrente(50);

        }
    }

    /**
     * onScannedRobot: Evento que ocorre quando outro robô é avistado
     */
    public void onScannedRobot(ScannedRobotEvent e) {
        double bearing = e.getBearing();
        // 7. Utilizando if na estratégia
        if (getGunHeat() > 0) {
            // Fugir
            passos = 10;
            turnLeft(bearing);
            return;
        }
        if (e.getDistance() < 500) {
            double carga = Rules.MIN_BULLET_POWER;
            if (e.getDistance() < 100) {
                carga = Rules.MAX_BULLET_POWER; // 8. Utilização de constante da classe Rules
            }
            atirar(carga); // 6. Chamada a método apelido
            if (e.getDistance() < 100) {
                andarPraTras(50);
            }
        }
        // Tentar ir atrás do outro robo

        turnLeft(-bearing);

        System.out.printf("Scanned e.getBearing = %f \n", bearing);
    }

    /**
     * onHitByBullet: O quê fazer quando for atingido por uma bala
     */
    public void onHitByBullet(HitByBulletEvent e) {
        // 6. Chamada a método apelido
        andarPraTras(20);
        virarPraTras();
    }

    /**
     * onHitWall: O quê fazer quando bater na parede
     */
    public void onHitWall(HitWallEvent e) {
        back(20);
        String d;
        double bearing = gerador.nextDouble() * e.getBearing();

        // 7. Utilizando if na estratégia
        if (bearing > 0) {
            //
            d = "Direita";
            turnLeft(bearing);
        } else {
            d = "Esquerda";
            turnRight(bearing);
        }

        System.out.printf("HitWall e.getBearing = %f %s \n", bearing, d);
        turnLeft(90);
    }

    /**
     * OnHitRobot: o que fazer quando bater em outro robô 9.d
     * 
     * @param event
     */
    public void OnHitRobot(HitRobotEvent event) {
        andarPraTras(50);
    }

    /**
     * OnWin: o que fazer quando o robô ganhar a rodada
     * 
     * @param event
     */
    public void onWin(WinEvent event) {
        log("Vitória");
    }

    /**
     * 5.a virarPraDireita: apelido para turnRight(90)
     */
    public void virarPraDireita() {
        turnRight(90);
    }

    /**
     * 5.b virarPraEsquerda: apelido para turnLeft(90)
     */
    public void virarPraEsquerda() {
        turnLeft(90);
    }

    /**
     * 5.c virarPraTras: apelido para turnLeft(180)
     */
    public void virarPraTras() {
        turnLeft(180);
    }

    /**
     * 5.d andarPraFrente: apelido para ahead
     * 
     * @param quantosPixels
     */
    public void andarPraFrente(double quantosPixels) {
        ahead(quantosPixels);
    }

    /**
     * 5.e andarPraTras: apelido para back
     * 
     * @param quantosPixels
     */
    public void andarPraTras(double quantosPixels) {
        back(quantosPixels);
    }

    /**
     * 5.f atirar: apelido para fire
     * 
     * @param energiaDaBala
     */
    public void atirar(double energiaDaBala) {
        fire(energiaDaBala);
    }

    /**
     * 5.g parar: apelido para stop
     */
    public void parar() {
        stop();
    }

    /**
     * Informação de log
     * 
     * @param mensagem texto a ser registrado
     */
    public void log(String mensagem) {
        System.out.println(mensagem);
    }
}