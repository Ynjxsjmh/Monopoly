public class ResolutionMenu extends Menu {
    protected void show() {
        System.out.println("\n\tSet resolution");
        System.out.println("1. 640X320");
        System.out.println("2. 800X600");
        System.out.println("3. 1024X768");
		System.out.println("-1. Back");
        System.out.println("Your choice is:");
    }

    public boolean doChoice(int choice) {
        switch(choice) {
        case 1: { System.out.println("Resolution has been set to 640X320");  break; }
        case 2: { System.out.println("Resolution has been set to 800X600");  break; }
        case 3: { System.out.println("Resolution has been set to 1024X768"); break; }
        default: { game.setCurrentMenu(MenuID.OPTION_MENU); }
        }
		// There is no break statement after case. Because after choosing, the menu should be set to option menu in case that players want to set the volume menu
		return true;
    }
}