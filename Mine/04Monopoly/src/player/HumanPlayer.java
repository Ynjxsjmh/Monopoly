package player;

import java.util.Scanner;

public class HumanPlayer extends Player {

	public HumanPlayer(String name) {
		super(name);
		// TODO Auto-generated constructor stub
		this.playerType = "HUMAN_TYPE";
	}

	@Override
	public void doAction() {
		// TODO Auto-generated method stub
		int choice = 0;
        Scanner scanner = new Scanner(System.in);
        choice = scanner.nextInt();
	}
}
