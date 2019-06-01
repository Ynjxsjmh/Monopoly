package state;

import player.Player;

public abstract class State {
	protected int turn; // define this state lasts how many turns
	protected int step;
	protected boolean isInvincible; // Can the player get rid of block effect
	protected Player targetPlayer;
	protected StateType stateType;

	public State(Player targetPlayer) {
		// TODO Auto-generated constructor stub
		this.targetPlayer = targetPlayer;
		this.isInvincible = false;
	}

	public int getTurn() {
		return this.turn;
	}

	public void setTurn(int turn) {
		this.turn = turn;
	}

	public int getStep() {
		return step;
	}

	public void setStep(int step) {
		this.step = step;
	}

	public StateType getStateType() {
		return this.stateType;
	}

	public abstract void operate();
}
