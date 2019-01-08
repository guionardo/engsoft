package progsis2;

import robocode.*;
import java.awt.Color;
import java.util.Random;

/**
 * Guionardo2 - a robot by Guionardo Furlan 1. Construa a classe para seu robô
 * estendendo a classe Robot disponível no pacote robocode.
 */
public class Guionardo2 extends Robot {
    private Random gerador = new Random();
    private int passos = 10;

    /**
     * run: Guionardo2's comportamento padrão 4. Sobrescrevendo o método run
     */
    public void run() {
        System.out.println("INIT Guionardo2");
        // 2. Altere a cor do seu robô
        setBodyColor(Color.red);
        // 3. Altere a cor da bala
        setBulletColor(Color.orange);

        // Robot main loop
        while (true) {
            // A cada 10 passos, muda a direção aleatoriamente
            if (passos > 0) {
                passos--;
            } else {
                turnLeft(gerador.nextFloat() * 360f - 180f);
                passos = 10;
            }
            andarPraFrente(100);
            turnGunRight(360);
        }
    }

    /**
     * onScannedRobot: What to do when you see another robot
     */
    public void onScannedRobot(ScannedRobotEvent e) {
        // Replace the next line with any behavior you would like
        double bearing = e.getBearing();

        if (getGunHeat() > 0) {
            // Fugir
            passos = 10;
            turnLeft(bearing);
            return;
        }
        if (e.getDistance() < 500) {
            double carga = Rules.MIN_BULLET_POWER;
            if (e.getDistance() < 100) {
                carga = Rules.MAX_BULLET_POWER;
            }
            atirar(carga);
            if (e.getDistance() < 100) {
                andarPraTras(50);
            }
        }
        // Tentar ir atrás do outro robo

        turnLeft(-bearing);

        System.out.printf("Scanned e.getBearing = %f \n", bearing);
    }

    /**
     * onHitByBullet: What to do when you're hit by a bullet
     */
    public void onHitByBullet(HitByBulletEvent e) {
        virarPraTras();
        andarPraFrente(20);
    }

    /**
     * onHitWall: What to do when you hit a wall
     */
    public void onHitWall(HitWallEvent e) {
        // Replace the next line with any behavior you would like
        back(20);
        String d;
        double bearing = gerador.nextDouble() * e.getBearing();

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
        System.out.println("Vitória");
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
}
