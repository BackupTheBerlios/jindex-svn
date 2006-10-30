package org.jindex.test;

import utils.c.libJIndex;
import junit.framework.TestCase;
import junit.framework.TestSuite;
import junit.textui.TestRunner;

public class NativeTest extends TestCase {
    /**
     * 
     * @param name 
     */
	public NativeTest(String name) {
		super(name);
	}

    /**
     * 
     * @param args 
     */
	public static void main(String[] args) {
		TestRunner.runAndWait(new TestSuite(NativeTest.class));
	}

    /**
     * 
     * @throws java.lang.Exception 
     */
	public void testGetName() throws Exception {
		String mimetype = libJIndex.getMimeType("/etc/passwd");
		assertEquals("text/plain", mimetype);
	}
}
