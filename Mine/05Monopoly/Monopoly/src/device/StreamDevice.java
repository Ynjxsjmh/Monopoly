package device;
public class StreamDevice extends OutDevice {
	public void draw(String pstr) {
		System.out.print(pstr);
	}
	
	public void drawLn(String pstr) {
		System.out.println(pstr);
	}
}