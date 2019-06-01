public class SaveMenu extends Menu {
    protected void show() {
        System.out.println("\n\tSelect the Record to save(1-5):");
        System.out.println("1. 1");
        System.out.println("2. 2");
        System.out.println("3. 3");
        System.out.println("4. 4");
        System.out.println("5. 5");
        System.out.println("-1. Back");
        System.out.println("Your choice is:");
    }

    public boolean doChoice(int choice) {
        switch(choice) {
        case 1: { System.out.println("建立存档1"); break; }
        case 2: { System.out.println("建立存档2"); break; }
        case 3: { System.out.println("建立存档3"); break; }
        case 4: { System.out.println("建立存档4"); break; }
        case 5: { System.out.println("建立存档5"); break; }
        default: { game.setCurrentMenu(MenuID.MAIN_MENU); }
        }
		return true;
    }
}