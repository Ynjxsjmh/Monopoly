package skill;

import game.Game;
import player.Player;
import state.StateFactory;
import state.StateType;

public class FlyCard extends Card{
	public FlyCard(Player executePlayer) {
		super(executePlayer);
		this.skillType = SkillType.CARD;
		this.stateType = StateType.FLY;
		this.cardName = CardType.FLY_CARD;
		this.skillName = this.cardName.toString();
	}
	
	@Override
	public void execute(int targetPlayerNum) {
		Player targetPlayer = Game.getGame().getSpecificPlayer(targetPlayerNum);
		targetPlayer.addState(StateFactory.createState(stateType, targetPlayer));
	}
}
