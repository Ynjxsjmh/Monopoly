public class WindowsMenuMgr extends MenuMgr {
	Menu createMainMenu() {
		return new WindowsMainMenu();
	}
	Menu createPlayersMenu(){
		return new WindowsPlayersMenu();
	}
	Menu createLoadMenu(){
		return new WindowsLoadMenu();
	}
	Menu createSaveMenu(){
		return new WindowsSaveMenu();
	}
	Menu createOptionMenu(){
		return new WindowsOptionMenu();
	}
	Menu createVolumeMenu(){
		return new WindowsVolumeMenu();
	}
	Menu createResolutionMenu(){
		return new WindowsResolutionMenu();
	}
}