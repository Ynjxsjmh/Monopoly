package menu;

import device.OutDevice;
import game.Game;
import player.Player;

public class PlayMenu extends Menu{
	public PlayMenu(int menuType) {
		super(menuType);
	}
	
    protected void show(OutDevice outDevice) {
        outDevice.drawLn("\n\tPlayMenu:");
        outDevice.drawLn("1. Go¡­");
        outDevice.drawLn("2. Load");
        outDevice.drawLn("3. Save");
        outDevice.drawLn("4. Back To MainMenu");
        outDevice.draw("Your choice is: ");
    }

    public boolean doChoice(int choice, OutDevice outDevice) {
    	// human and computers do different thing here.
    	// human do choice but computer go on directly
    	
    	Player player = Game.getGame().players.poll();
    	System.out.println("--------------------------------------------------");
    	System.out.println("PlayMenu.doChoice()");
    	System.out.println("current player is " + player.getName());
    	System.out.println("His type is "+ player.getType());
    	System.out.println("--------------------------------------------------");
    	Game.getGame().players.offer(player);
		
        switch(choice) {
        case 1: { 
        		  Game.getGame().getCurrentMap().show(); 

          		  Game.getGame().setCurrentMenu(MenuID.PLAY_MENU);
        		  break; }  // show current map
        case 2: { Game.getGame().setCurrentMenu(MenuID.LOAD_MENU); break; }
        case 3: { Game.getGame().setCurrentMenu(MenuID.SAVE_MENU); break; }
        case 4: { Game.getGame().setCurrentMenu(MenuID.MAIN_MENU);  break; }
        default: { Game.getGame().setCurrentMenu(MenuID.PLAY_MENU); break; }
        }
		
		return true;
    }
}
