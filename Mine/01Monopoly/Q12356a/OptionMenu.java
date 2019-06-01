public class OptionMenu extends Menu {
	public OptionMenu() {
		super();
	}
	
    protected void show() {
        System.out.println("\n\tSet options");
        System.out.println("1. Set the value of Volume(0-100)");
        System.out.println("2. Set the resolution");
		System.out.println("-1. Back");
        System.out.println("Your choice is:");
    }

    public boolean doChoice(int choice) {
        switch(choice) {
        case 1: { Game.getGame().setCurrentMenu(MenuID.VOLUME_MENU); break;}
        case 2: { Game.getGame().setCurrentMenu(MenuID.RESOLUTION_MENU); break; }
        default: { Game.getGame().setCurrentMenu(MenuID.MAIN_MENU); break; }
        }
		return true;
   }
}