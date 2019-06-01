package player;

import state.NormalState;
import visitor.Visitor;

public class NormalPlayer extends Player {

	public NormalPlayer(int id) {
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

	public void accept(Visitor visitor) {
		visitor.visit(this);
	}
}
