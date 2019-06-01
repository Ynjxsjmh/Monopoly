package skill;

import game.Game;
import player.Player;
import state.StateFactory;
import state.StateType;

public class ExFlyCard extends Card {
	public ExFlyCard(Player executePlayer) {
		super(executePlayer);
		this.skillType = SkillType.CARD;
		this.stateType = StateType.EXFLY;
		this.cardName = CardType.EXFLY_CARD;
		this.skillName = this.cardName.toString();
	}

	@Override
	public void execute(int targetPlayerNum) {
		Player targetPlayer = Game.getGame().getSpecificPlayer(targetPlayerNum);
		targetPlayer.addState(StateFactory.createState(stateType, targetPlayer));
	}
}
