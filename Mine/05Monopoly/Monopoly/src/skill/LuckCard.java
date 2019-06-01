package skill;

import game.Game;
import player.Player;
import state.StateType;
import visitor.ApplyLuckVisitor;
import visitor.Visitor;

public class LuckCard extends Card {

	public LuckCard(Player executePlayer) {
		super(executePlayer);
		this.skillType = SkillType.CARD;
		this.stateType = StateType.LUCK;
		this.cardName = CardType.LUCK_CARD;
		this.skillName = this.cardName.toString();
	}

	@Override
	public void execute(int targetPlayerNum) {
		Player targetPlayer = Game.getGame().getSpecificPlayer(targetPlayerNum);
		this.apply(targetPlayer);
	}
	
	public void apply(Player targetPlayer) {
		Visitor applyLuckVisitor = new ApplyLuckVisitor(this);
		targetPlayer.accept(applyLuckVisitor);
	}
}
