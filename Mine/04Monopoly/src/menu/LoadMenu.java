package menu;

import device.OutDevice;
import game.Game;

public class LoadMenu extends Menu {
	public LoadMenu(int menuType) {
		super(menuType);
	}
	
    protected void show(OutDevice outDevice) {
        outDevice.drawLn("\n\tSelect the Record to be loaded(1-5):");
        outDevice.drawLn("1. 1");
        outDevice.drawLn("2. 2");
        outDevice.drawLn("3. 3");
        outDevice.drawLn("4. 4");
        outDevice.drawLn("5. 5");
        outDevice.drawLn("-1. Back");
        outDevice.draw("Your choice is: ");
    }

    public boolean doChoice(int choice, OutDevice outDevice) {
        switch(choice) {
        case 1: { outDevice.drawLn("¥Êµµ1º”‘ÿÕÍ±œ"); break; }
        case 2: { outDevice.drawLn("¥Êµµ2º”‘ÿÕÍ±œ"); break; }
        case 3: { outDevice.drawLn("¥Êµµ3º”‘ÿÕÍ±œ"); break; }
        case 4: { outDevice.drawLn("¥Êµµ4º”‘ÿÕÍ±œ"); break; }
        case 5: { outDevice.drawLn("¥Êµµ5º”‘ÿÕÍ±œ"); break; }
        default: { Game.getGame().setCurrentMenu(MenuID.MAIN_MENU); }
        }
		Game.getGame().setCurrentMenu(MenuID.PLAY_MENU); 
		return true;
    }
}