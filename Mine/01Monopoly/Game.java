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
	//		System.out.println("���ڷ���Game");
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
            // choice = currentMenu.process();  //�����˵�����ѡ��ѡ�������Ӳ˵�
            // running = currentMenu.doChoice(choice);
            // setCurrentMenu(choice);

            // choice = currentMenu.process();  //���Ӳ˵�����ѡ��ÿ���Ӳ˵���ѡ����ֳ���ͬ����Ϊ��ѡ��Ϊ0��������һ���˵���
        }
    }

    public void term() {
    }

    public void setCurrentMenu(int menuID) {

        currentMenu = menuMgr.createMenu(menuID);
    }
}