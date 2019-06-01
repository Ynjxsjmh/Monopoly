package menu;

import device.OutDevice;
import device.StreamDevice;

public class MenuMgr {
	private static Menu[] menuList;
	public Menu currentMenu;

	protected static MenuMgr uniqueMenuMgr = new MenuMgr();

	protected MenuMgr() {
		menuList = new Menu[MenuID.MENU_COUNT];
		menuList[MenuID.MAIN_MENU] = new MainMenu(MenuID.MAIN_MENU);
		menuList[MenuID.PLAYERS_MENU] = new PlayersMenu(MenuID.PLAYERS_MENU);
		menuList[MenuID.LOAD_MENU] = new LoadMenu(MenuID.LOAD_MENU);
		menuList[MenuID.SAVE_MENU] = new SaveMenu(MenuID.SAVE_MENU);
		menuList[MenuID.OPTION_MENU] = new OptionMenu(MenuID.OPTION_MENU);
		menuList[MenuID.VOLUME_MENU] = new VolumeMenu(MenuID.VOLUME_MENU);
		menuList[MenuID.RESOLUTION_MENU] = new ResolutionMenu(MenuID.RESOLUTION_MENU);
		menuList[MenuID.PLAY_MENU] = new PlayMenu(MenuID.PLAY_MENU);
	}

	public static MenuMgr getMenuMgr() {
		// if (uniqueMenuMgr == null) {
		// uniqueMenuMgr = new MenuMgr();
		// }
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
		OutDevice outDevice = new StreamDevice();
		mainMenu.show(outDevice);

		Menu optionMenu = menuMgr.createMenu(MenuID.OPTION_MENU);
		optionMenu.show(outDevice);

		MenuMgr menuMgr2 = MenuMgr.getMenuMgr();
		Menu optionMenu2 = menuMgr2.createMenu(MenuID.OPTION_MENU);
		optionMenu2.show(outDevice);
	}
}