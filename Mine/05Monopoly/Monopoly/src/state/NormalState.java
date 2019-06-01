package state;

import player.Player;

public class NormalState extends State {
	// in normal state, player's step is their original step
	public NormalState(Player targetPlayer) {
		super(targetPlayer);
		this.turn = Integer.MAX_VALUE;
		this.step = targetPlayer.getStep();
		this.stateType = StateType.NORMAL;
	}

	@Override
	public void operate() {
		targetPlayer.getMoveStrategy().setStep(targetPlayer.getStep());
		-- this.turn;
	}
}
