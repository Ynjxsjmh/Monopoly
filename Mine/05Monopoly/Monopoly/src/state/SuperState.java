package state;

import player.Player;

public class SuperState extends State {
	// it has both the function of FlyState and LuckState
	// it lasts 1 turn
	public SuperState(Player targetPlayer) {
		super(targetPlayer);
		this.stateType = StateType.SUPER;
		this.turn = 1;
	}

	@Override
	public void operate() {
		State flyState = new FlyState(targetPlayer);
		State luckState = new LuckState(targetPlayer);
		
		flyState.operate();
		luckState.operate();
		
		-- this.turn;
	}
}
