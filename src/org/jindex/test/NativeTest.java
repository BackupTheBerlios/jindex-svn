package org.jindex.test;

import utils.c.libInotify;
import utils.c.libJIndex;
import junit.framework.TestCase;
import junit.framework.TestSuite;
import junit.textui.TestRunner;

public class NativeTest extends TestCase {
	public NativeTest(String name) {
		super(name);
	}

	public static void main(String[] args) {
		TestRunner.runAndWait(new TestSuite(NativeTest.class));
	}

	public void testJIndex() throws Exception {
		String mimetype = libJIndex.getMimeType("/etc/passwd");
		assertEquals("text/plain", mimetype);
	}
	public void testlibInotidy() throws Exception {
		libInotify.registerWatch("/etc/passwd");
	}
}
