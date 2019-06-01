package state;

import player.Player;

public class HurtState extends State {
	// in hurt state, player's money decreases 5 every turn
	// this state lasts 2 turn
	public HurtState(Player targetPlayer) {
		super(targetPlayer);
		this.stateType = StateType.HURT;
		this.turn = 2;
	}

	@Override
	public void operate() {
		this.targetPlayer.money -= 5;
		-- this.turn;
	}
}
