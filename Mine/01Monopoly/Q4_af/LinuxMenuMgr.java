public class LinuxMenuMgr extends MenuMgr {
	Menu createMainMenu() {
		return new LinuxMainMenu();
	}
	Menu createPlayersMenu(){
		return new LinuxPlayersMenu();
	}
	Menu createLoadMenu(){
		return new LinuxLoadMenu();
	}
	Menu createSaveMenu(){
		return new LinuxSaveMenu();
	}
	Menu createOptionMenu(){
		return new LinuxOptionMenu();
	}
	Menu createVolumeMenu(){
		return new LinuxVolumeMenu();
	}
	Menu createResolutionMenu(){
		return new LinuxResolutionMenu();
	}
}