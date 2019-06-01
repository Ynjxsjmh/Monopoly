package skill;

import game.Game;
import player.Player;
import state.StateFactory;
import state.StateType;

public class FreezeMagic extends Magic{
	// 
	public FreezeMagic(Player executePlayer) {
		super(executePlayer);
		this.skillType = SkillType.MAGIC;
		this.stateType = StateType.FREEZE;
		this.magicName = MagicType.FREEZE_MAGIC;
		this.skillName = this.magicName.toString();
	}
	
	@Override
	public void execute(int targetPlayerNum) {
		Player targetPlayer = Game.getGame().getSpecificPlayer(targetPlayerNum);
		targetPlayer.addState(StateFactory.createState(stateType, targetPlayer));
	}
}
