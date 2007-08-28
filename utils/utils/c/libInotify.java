package utils.c;

/**
 * @author sorenm
 */
public class libInotify {
	static {
		System.out.println("loading library Inotify");
		System.loadLibrary("Inotify");
	}

	public static native void registerWatch(String filename);

	public static native void removeWatch(String filename);

	public void callbackNotifyEvent(String filename) {
		System.out.println("Callback called");
	}

}
