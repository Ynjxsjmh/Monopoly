package skill;

import game.Game;
import player.Player;
import state.StateFactory;
import state.StateType;

public class SuperCard extends Card {

	public SuperCard(Player executePlayer) {
		super(executePlayer);
		this.skillType = SkillType.CARD;
		this.stateType = StateType.SUPER;
		this.cardName = CardType.SUPER_CARD;
		this.skillName = this.cardName.toString();
	}

	@Override
	public void execute(int targetPlayerNum) {
		Player targetPlayer = Game.getGame().getSpecificPlayer(targetPlayerNum);
		targetPlayer.addState(StateFactory.createState(stateType, targetPlayer));
	}
}
