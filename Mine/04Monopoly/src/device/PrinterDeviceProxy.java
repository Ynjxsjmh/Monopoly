package device;
public class PrinterDeviceProxy extends OutDevice {
	private PrinterDevice printerDevice;
	
	public PrinterDeviceProxy(PrinterDevice printerDevice) {
		this.printerDevice = printerDevice;
	}
	
	public void draw(String pstr) {
		this.printerDevice.draw(pstr);
	}
	
	public void drawLn(String pstr) {
		this.printerDevice.drawLn(pstr);
	}
}