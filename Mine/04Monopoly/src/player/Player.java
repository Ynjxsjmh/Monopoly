package player;

public abstract class Player {
	protected String playerName;
	protected String playerType;  // should be autoplayer or humanplayer
	
	public Player(String name) {
		// TODO Auto-generated constructor stub
		this.playerName = name;
	}
	
	public String getName() {
		return this.playerName;
	}
	
	public String getType() {
		return this.playerType;
	}
	
	public abstract void doAction();

}
