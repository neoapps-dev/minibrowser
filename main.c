#include <gtk/gtk.h>
#include <webkit2/webkit2.h>
int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 1920, 1080);
    gtk_window_fullscreen(GTK_WINDOW(window));
    WebKitWebView *webview = WEBKIT_WEB_VIEW(webkit_web_view_new());
    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(webview));
    webkit_web_view_load_uri(webview, argv[1] ? argv[1] : "https://example.com");
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
