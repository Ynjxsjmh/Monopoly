package device;
public class SpaceDecorator extends OutDeviceDecorator {
	public OutDevice outDevice;
	
	public SpaceDecorator(OutDevice outDevice) {
		this.outDevice = outDevice;
	}
	
	public void draw(String pstr) {
		System.out.print("    " + pstr);
	}
	
	public void drawLn(String pstr) {
		System.out.println("    " + pstr);
	}
}