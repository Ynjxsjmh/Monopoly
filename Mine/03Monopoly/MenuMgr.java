public class MenuMgr {
    private static Menu[] menuList;
	public Menu currentMenu;

    protected static MenuMgr uniqueMenuMgr = new MenuMgr();

    protected MenuMgr() {
        menuList = new Menu[MenuID.MENU_COUNT];
        menuList[MenuID.MAIN_MENU] = new MainMenu();
        menuList[MenuID.PLAYERS_MENU] = new PlayersMenu();
        menuList[MenuID.LOAD_MENU] = new LoadMenu();
        menuList[MenuID.SAVE_MENU] = new SaveMenu();
        menuList[MenuID.OPTION_MENU] = new OptionMenu();
        menuList[MenuID.VOLUME_MENU] = new VolumeMenu();
        menuList[MenuID.RESOLUTION_MENU] = new ResolutionMenu();
    }

    public static MenuMgr getMenuMgr(){
        //if (uniqueMenuMgr == null) {
        //    uniqueMenuMgr = new MenuMgr();
        //}
        return uniqueMenuMgr;
    }

    public Menu createMenu(int menuID) {
        if (menuID < MenuID.MENU_COUNT && menuID >= 0) {
            return menuList[menuID];
        }
        return menuList[MenuID.MAIN_MENU];
    }

	public static void main(String[] args) {
		MenuMgr menuMgr = MenuMgr.getMenuMgr();
		Menu mainMenu = menuMgr.createMenu(MenuID.MAIN_MENU);
        mainMenu.show();

        Menu optionMenu = menuMgr.createMenu(MenuID.OPTION_MENU);
		optionMenu.show();

        MenuMgr menuMgr2 = MenuMgr.getMenuMgr();
		Menu optionMenu2 = menuMgr2.createMenu(MenuID.OPTION_MENU);
		optionMenu2.show();
	}
}