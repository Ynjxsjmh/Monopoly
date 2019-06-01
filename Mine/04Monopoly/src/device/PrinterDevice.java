package device;
public class PrinterDevice extends OutDevice {
	public void draw(String pstr) {
		System.out.print(pstr + "-------打印机处�?");
	}
	
	public void drawLn(String pstr) {
		System.out.println(pstr + "-------打印机处�?");
	}
}