package player;

import java.util.Scanner;

public class HumanPlayer extends Player {

	public HumanPlayer(String name) {
		super(name);
		this.x = 0;
		this.y = 0;
		this.playerType = "HUMAN_TYPE";
		this.describe = "[" + name + "]";
	}

	@Override
	public void doAction() {
		// TODO Auto-generated method stub
		int choice = 0;
		Scanner scanner = new Scanner(System.in);
		choice = scanner.nextInt();
	}
}
