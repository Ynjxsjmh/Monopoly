package state;

import player.Player;

public class StateFactory {

	public static State createState(StateType stateType, Player targetPlayer) {
		switch (stateType) {
		case EXFLY:
			return new ExFlyState(targetPlayer);
		case FLY:
			return new FlyState(targetPlayer);
		case FREEZE:
			return new FreezeState(targetPlayer);
		case HURT:
			return new HurtState(targetPlayer);
		case LUCK:
			return new LuckState(targetPlayer);
		case NORMAL:
			return new NormalState(targetPlayer);
		case SUPER:
			return new SuperState(targetPlayer);
		default:
			return null;
		}
	}
}
