package player;

public class AutoPlayer extends Player {
	public AutoPlayer(String name) {
		super(name);
		this.x = 1;
		this.y = 0;
		this.playerType = "AUTO_TYPE";
		this.describe = "(" + name + ")";
	}

	@Override
	public void doAction() {
		// TODO Auto-generated method stub
		
	}
}
