package state;

import player.Player;

public class ExFlyState extends State {
	// In addition to having the function of FlyState
	// Also the player could get rid of the side effect of Block
	// In return, it lasts the same turn with FlyState, which is 2
	public ExFlyState(Player targetPlayer) {
		super(targetPlayer);
		this.stateType = StateType.EXFLY;
		this.turn = 2;
		this.isInvincible = true;
	}

	@Override
	public void operate() {
		State flyState = new FlyState(targetPlayer);
		flyState.operate();
		-- this.turn;
	}
}
