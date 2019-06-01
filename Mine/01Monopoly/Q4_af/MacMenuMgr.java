public class MacMenuMgr extends MenuMgr {
	Menu createMainMenu() {
		return new MacMainMenu();
	}
	Menu createPlayersMenu(){
		return new MacPlayersMenu();
	}
	Menu createLoadMenu(){
		return new MacLoadMenu();
	}
	Menu createSaveMenu(){
		return new MacSaveMenu();
	}
	Menu createOptionMenu(){
		return new MacOptionMenu();
	}
	Menu createVolumeMenu(){
		return new MacVolumeMenu();
	}
	Menu createResolutionMenu(){
		return new MacResolutionMenu();
	}
}