package visitor;

import player.NormalPlayer;
import player.TWHPlayer;
import player.WWBPlayer;
import skill.Card;
import skill.LuckCard;
import state.State;
import state.StateFactory;
import state.StateType;

public class ApplyLuckVisitor implements ApplyVisitor {
	private Card card;
	private StateType stateType;

	public ApplyLuckVisitor(LuckCard card) {
		this.card = card;
		this.stateType = this.card.getStateType();  // it's just LUCK Type
	}

	@Override
	public void visit(NormalPlayer normalPlayer) {
		State state = StateFactory.createState(stateType, normalPlayer);
		normalPlayer.addState(state);
	}

	@Override
	public void visit(TWHPlayer thwPlayer) {
		State state = StateFactory.createState(stateType, thwPlayer);
		state.setTurn(3);
		thwPlayer.addState(state);
	}

	@Override
	public void visit(WWBPlayer wwbPlayer) {
		State state = StateFactory.createState(stateType, wwbPlayer);
		state.setTurn(4);
		wwbPlayer.addState(state);
	}
}
