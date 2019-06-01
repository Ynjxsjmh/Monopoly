package state;

import player.Player;

public class FreezeState extends State {
	// in freeze state, player's step decreases to 1 and lasts 3 turns
	public FreezeState(Player targetPlayer) {
		super(targetPlayer);
		this.turn = 3;
		this.step = 1;
		this.stateType = StateType.FREEZE;
	}

	@Override
	public void operate() {
		targetPlayer.getMoveStrategy().setStep(this.step);
		-- this.turn;
	}

}
