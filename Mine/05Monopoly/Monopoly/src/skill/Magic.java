package skill;

import player.Player;

public abstract class Magic extends Skill {
	protected MagicType magicName;
	
	public Magic(Player executePlayer) {
		this.executePlayer = executePlayer;
	}
	
	public MagicType getMagicName() {
		return this.magicName;
	}
}
