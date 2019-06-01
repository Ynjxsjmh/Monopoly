package strategy;

import player.Player;

public abstract class MoveStrategy {
	protected Player currentPlayer;
	protected int step;
	
	public MoveStrategy(Player currentPlayer) {
		this.currentPlayer = currentPlayer;
		this.step = this.currentPlayer.getStep();
	}

	public abstract void move();
	
	public void setStep(int step) {
		this.step = step;
	}
}
