package progsis2;

import robocode.*;
import java.util.Random;
import java.awt.Color;

// API help : http://robocode.sourceforge.net/docs/robocode/robocode/Robot.html

/**
 * GuionardoFurlan - a robot by Guionardo Furlan
 */
public class GuionardoFurlan extends Robot {

	// Variável que indica que foi encontrado um robo no scanner e
	private int Cacando = 0;

	// Inicializa gerador de números randômicos
	Random gerador = new Random();

	/**
	 * run: GuionardoFurlan's default behavior
	 */
	public void run() {
		// 2. Altere a cor do seu robô.
		setBodyColor(Color.green);

		// 3. Altere a cor da bala.
		setBulletColor(Color.red);

		// Robot main loop
		while (true) {

			if (Cacando > 0) {
				// se estiver caçando, após um OnScannedRobot
				Cacando--;
				andarPraFrente(100);
			} else {
				// Distância aleatória entre 10 e 100
				int distancia = 10 + gerador.nextInt(90);
				if (gerador.nextBoolean()) {
					// true = para frente
					andarPraFrente(distancia);
				} else {
					// false = para trás
					andarPraTras(distancia);
				}

				// Mudança de direção entre 0 e 180 graus
				int bearing = gerador.nextInt(180);
				if (gerador.nextBoolean()) {
					// true = para esquerda
					turnLeft(bearing);
				} else {
					// false = para direita
					turnRight(bearing);
				}
			}

			// Girar a arma 360 graus para ativar o scanner
			turnGunRight(360);

		}
	}

	/**
	 * Comemora quando não há nenhum oponente
	 */
	public void Comemorar() {
		int quanto = 100;
		andarPraFrente(quanto);
		virarPraDireita();
	}

	/**
	 * onScannedRobot: O que fazer quando visualizar outro robô 9.a
	 */
	public void onScannedRobot(ScannedRobotEvent e) {
		if (getGunHeat() == 0) {
			// Arma quente, não pode atirar
			// Fugir na direção contrária
			turnLeft(180 - e.getBearing());
		} else {
			atirar(1);
			turnLeft(e.getBearing());
			Cacando = 4; // Caça na direção do robô por 4 rodadas
		}
	}

	/**
	 * onHitByBullet: O que fazer quando atingido por outro robô 9.b
	 */
	public void onHitByBullet(HitByBulletEvent e) {
		// Virar 90 graus a esquerda do tiro e voltar
		turnLeft(90 - e.getBearing());
		back(10);
	}

	/**
	 * onHitWall: O que fazer quando bater em uma parede 9.c
	 */
	public void onHitWall(HitWallEvent e) {
		back(20);
		turnLeft(90 - e.getBearing());
	}

	/**
	 * OnHitRobot: o que fazer quando bater em outro robô 9.d
	 * 
	 * @param event
	 */
	public void OnHitRobot(HitRobotEvent event) {

	}

	/**
	 * OnWin: o que fazer quando o robô ganhar a rodada
	 * 
	 * @param event
	 */
	public void onWin(WinEvent event) {

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
