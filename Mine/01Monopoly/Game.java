public class Game {
    private MenuMgr menuMgr;
    private Menu currentMenu;
    private int choice;
    private static Game uniqueGame = new Game();

    private Game() {
        menuMgr = MenuMgr.getMenuMgr();
    }

    public static Game getGame() {
    //    if (uniqueGame == null) {
	//		System.out.println("正在返回Game");
    //        uniqueGame = new Game();
    //    }
        return uniqueGame;
    }

    public void init() {
        setCurrentMenu(MenuID.MAIN_MENU);
    }

    public void run() {
        boolean running = true;
        while (running) {
            running = currentMenu.process();
            // choice = currentMenu.process();  //对主菜单进行选择，选择后进入子菜单
            // running = currentMenu.doChoice(choice);
            // setCurrentMenu(choice);

            // choice = currentMenu.process();  //对子菜单进行选择，每个子菜单对选项表现出不同的行为。选择为0，返回上一级菜单。
        }
    }

    public void term() {
    }

    public void setCurrentMenu(int menuID) {

        currentMenu = menuMgr.createMenu(menuID);
    }
}