package player;

import map.DirectionID;

public abstract class Player {
	public int x;
	public int y;
	public int direction;
	
	protected String playerName;
	protected String playerType;  // should be AUTO_TYPE or HUMAN_TYPE
	protected String describe;
	
	public Player(String name) {
		// TODO Auto-generated constructor stub
		this.playerName = name;  // name actually is player id
		this.direction = DirectionID.DIR_DOWN;
	}
	
	public String getName() {
		return this.playerName;
	}
	
	public String getType() {
		return this.playerType;
	}
	
	public String show() {
		return this.describe;
	}
	
	public abstract void doAction();

}
