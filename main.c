#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    
    // Create window and increase reference count
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_object_ref(window);
    
    gtk_window_set_default_size(GTK_WINDOW(window), 1920, 1080);
    gtk_window_fullscreen(GTK_WINDOW(window));
    
    // Create webview and increase reference count
    WebKitWebView *webview = WEBKIT_WEB_VIEW(webkit_web_view_new());
    g_object_ref(webview);
    
    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(webview));
    webkit_web_view_load_uri(webview, argv[1] ? argv[1] : "https://example.com");
    
    // Set up cleanup on window destroy
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    gtk_widget_show_all(window);
    gtk_main();
    
    // Properly clean up resources
    gtk_widget_destroy(GTK_WIDGET(webview));
    g_object_unref(webview);
    
    gtk_widget_destroy(window);
    g_object_unref(window);
    
    return 0;
}
