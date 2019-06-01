package visitor;

import player.NormalPlayer;
import player.TWHPlayer;
import player.WWBPlayer;

public interface Visitor {
	public void visit(NormalPlayer normalPlayer);
	public void visit(TWHPlayer thwPlayer);
	public void visit(WWBPlayer wwbPlayer);
}
