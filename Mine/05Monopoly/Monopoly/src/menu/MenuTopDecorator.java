package menu;

import device.OutDevice;

public class MenuTopDecorator extends MenuDecorator {
	Menu menu;

	public MenuTopDecorator(Menu menu, int menuType) {
		// TODO Auto-generated constructor stub
		super(menuType);
		this.menu = menu;
	}

	@Override
	public boolean process() {
		// TODO Auto-generated method stub
		return menu.process();
	}

	@Override
	protected void show(OutDevice outDevice) {
		// TODO Auto-generated method stub
		String pstr = "\n=========================\n" + "=                       =\n" + "=========================";
		outDevice.drawLn(pstr);
		menu.show(outDevice);
	}

	@Override
	public boolean doChoice(int choice, OutDevice outDevice) {
		// TODO Auto-generated method stub
		return menu.doChoice(choice, outDevice);
	}
}
