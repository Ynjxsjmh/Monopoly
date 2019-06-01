package menu;

import javax.sound.sampled.*;
import java.io.File;
import java.io.IOException;
import javax.sound.sampled.LineEvent.Type;
import device.OutDevice;

public class MenuPlaySound extends MenuDecorator {
	Menu menu;

	public MenuPlaySound(Menu menu, int menuType) {
		// TODO Auto-generated constructor stub
		super(menuType);
		this.menu = menu;
	}

	@Override
	public boolean process() {
		// TODO Auto-generated method stub
		String pathname = "";        // ----------------- add Sound File here
		File clipFile = new File(pathname);
		try {
			playClip(clipFile);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (UnsupportedAudioFileException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (LineUnavailableException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return menu.process();
	}

	@Override
	protected void show(OutDevice outDevice) {
		// TODO Auto-generated method stub
		menu.show(outDevice);
	}

	@Override
	public boolean doChoice(int choice, OutDevice outDevice) {
		// TODO Auto-generated method stub
		return menu.doChoice(choice, outDevice);
	}

	private static void playClip(File clipFile)
			throws IOException, UnsupportedAudioFileException, LineUnavailableException, InterruptedException {
		class AudioListener implements LineListener {
			private boolean done = false;

			@Override
			public synchronized void update(LineEvent event) {
				Type eventType = event.getType();
				if (eventType == Type.STOP || eventType == Type.CLOSE) {
					done = true;
					notifyAll();
				}
			}

			public synchronized void waitUntilDone() throws InterruptedException {
				while (!done) {
					wait();
				}
			}
		}
		AudioListener listener = new AudioListener();
		AudioInputStream audioInputStream = AudioSystem.getAudioInputStream(clipFile);
		try {
			Clip clip = AudioSystem.getClip();
			clip.addLineListener(listener);
			clip.open(audioInputStream);
			try {
				clip.start();
				listener.waitUntilDone();
			} finally {
				clip.close();
			}
		} finally {
			audioInputStream.close();
		}
	}
}
