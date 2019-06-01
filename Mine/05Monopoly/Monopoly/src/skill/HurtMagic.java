package skill;

import game.Game;
import player.Player;
import state.StateFactory;
import state.StateType;

public class HurtMagic extends Magic{

	public HurtMagic(Player executePlayer) {
		super(executePlayer);
		this.skillType = SkillType.MAGIC;
		this.stateType = StateType.HURT;
		this.magicName = MagicType.HURT_MAGIC;
		this.skillName = this.magicName.toString();
	}

	@Override
	public void execute(int targetPlayerNum) {
		Player targetPlayer = Game.getGame().getSpecificPlayer(targetPlayerNum);
		targetPlayer.addState(StateFactory.createState(stateType, targetPlayer));
	}
}
