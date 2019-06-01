package state;

import player.Player;

public class FlyState extends State{
	// in fly state, player step increases to 6 and lasts 2 turns

	public FlyState(Player targetPlayer) {
		super(targetPlayer);
		this.turn = 2;
		this.step = 6;
		this.stateType = StateType.FLY;
	}

	@Override
	public void operate() {
		targetPlayer.getMoveStrategy().setStep(this.step);
		-- this.turn;
	}
}
