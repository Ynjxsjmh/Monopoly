package menu;
import device.OutDevice;
import game.Game;

public class OptionMenu extends Menu {
	public OptionMenu(int menuType) {
		super(menuType);
	}
	
    protected void show(OutDevice outDevice) {
        outDevice.drawLn("\n\tSet options");
        outDevice.drawLn("1. Set the value of Volume(0-100)");
        outDevice.drawLn("2. Set the resolution");
		outDevice.drawLn("-1. Back");
        outDevice.draw("Your choice is: ");
    }

    public boolean doChoice(int choice, OutDevice outDevice) {
        switch(choice) {
        case 1: { Game.getGame().setCurrentMenu(MenuID.VOLUME_MENU); break;}
        case 2: { Game.getGame().setCurrentMenu(MenuID.RESOLUTION_MENU); break; }
        default: { Game.getGame().setCurrentMenu(MenuID.MAIN_MENU); break; }
        }
		return true;
   }
}