package player;

import state.NormalState;
import visitor.Visitor;

public class TWHPlayer extends Player {
	// this player is tall, wealthy and handsome
	// when LuckCard is applied on him, the Card
	// effect will last 3 turns
	public TWHPlayer(int id) {
		super(id);
		this.step = 2;
		this.x = this.originalX = 1;
		this.y = this.originalY = 0;

		this.describe = "(" + id + ")";
		states.add(new NormalState(this));
	}

	@Override
	public void doAction() {
		// TODO Auto-generated method stub

	}

	@Override
	public void accept(Visitor visitor) {
		// TODO Auto-generated method stub
		visitor.visit(this);
	}
}
