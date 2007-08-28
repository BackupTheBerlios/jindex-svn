#include <stdio.h>
#include <gtk/gtk.h>
#include <libgnomevfs/gnome-vfs-init.h>
#include <libgnomevfs/gnome-vfs-mime-handlers.h>

#include "utils_c_libInotify.h"
#include <linux/inotify.h>

#include <glib.h>

#include <libinotify/libinotify.h>

#include <linux/inotify.h>

JNIEnv *mainenv;
jclass mainclass;

void my_callback(INotifyHandle *inh, const char *monitor_name, const char *name, guint32 event_type, gpointer user_data) {
	jmethodID callback;
	jstring filename;
	g_print("Got event %x on %s (file %s)n", event_type, monitor_name, name );

	callback = (*mainenv)->GetMethodID(mainenv, mainclass, "callbackNotifyEvent","(Ljava/lang/String;)V");
	if (callback== 0)
		g_warning("Unable to find method");
	
	filename = (*mainenv)->NewStringUTF(mainenv, monitor_name);
	g_warning("About to class method");
	
	(*mainenv)->CallVoidMethod(mainenv, mainclass, callback, filename);
	g_warning("Call method done");
}

JNIEXPORT void JNICALL Java_utils_c_libInotify_registerWatch(JNIEnv *env, jclass class, jstring filename) {
	INotifyHandle *inh;

	GMainLoop *main_loop;

	mainenv = env;
	mainclass = class;
	inh = inotify_monitor_add( "/home/sorenm/delme/test.c", IN_ALL_EVENTS, IN_FLAG_FILE_BASED, my_callback, NULL );

	g_warning( "Done adding watch" );
	main_loop = g_main_loop_new (NULL, FALSE);
	g_main_loop_run (main_loop);

	if( inh == NULL )
	g_warning( "monitor_add failed." );
}

JNIEXPORT void JNICALL Java_utils_c_libInotify_removeWatch (JNIEnv *env, jclass class, jstring filename) {
}

