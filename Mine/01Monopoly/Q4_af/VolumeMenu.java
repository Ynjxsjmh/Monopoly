public class VolumeMenu extends Menu {
    protected void show() {
        System.out.println("\n\tSet volume");
        System.out.println("1. input value(0-100)");
        System.out.println("-1. Back");
		System.out.println("Your set is:");
    }

    public boolean doChoice(int choice) {
        switch(choice) {
        case -1: { game.setCurrentMenu(MenuID.OPTION_MENU); break;}
        default: { System.out.println("Volume has been set to: " + choice); game.setCurrentMenu(MenuID.OPTION_MENU); }
        }
		return true;
    }
}