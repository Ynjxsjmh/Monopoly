package state;

import player.Player;

public class LuckState extends State {
	// in luck state, player's money increases 200 every turn
	// this state lasts 3 turns
	public LuckState(Player targetPlayer) {
		super(targetPlayer);
		this.stateType = StateType.LUCK;
		this.turn = 2;
	}

	@Override
	public void operate() {
		this.targetPlayer.money += 201;
		-- this.turn;
	}
}
