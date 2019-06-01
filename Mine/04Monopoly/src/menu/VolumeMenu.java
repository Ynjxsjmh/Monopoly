package menu;
import device.OutDevice;
import game.Game;

public class VolumeMenu extends Menu {
	public VolumeMenu(int menuType) {
		super(menuType);
	}
	
    protected void show(OutDevice outDevice) {
        outDevice.drawLn("\n\tSet volume");
        outDevice.drawLn("1. input value(0-100)");
        outDevice.drawLn("-1. Back");
		outDevice.draw("Your set is: ");
    }

    public boolean doChoice(int choice, OutDevice outDevice) {
        switch(choice) {
        case -1: { Game.getGame().setCurrentMenu(MenuID.OPTION_MENU); break;}
        default: { outDevice.drawLn("Volume has been set to: " + choice); Game.getGame().setCurrentMenu(MenuID.OPTION_MENU); }
        }
		return true;
    }
}