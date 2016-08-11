#include <gtk/gtk.h>

int main( int   argc,
          char *argv[] )
{
    printf("%s\n", "hello world");
    GtkWidget *window;
    
    gtk_init (&argc, &argv);
    
    window = gtk_window_new (GTK_WINDOW_POPUP);

    //gtk_window_set_decorated((GtkWindow*)window, 0);
    gtk_widget_show(window);
    
    gtk_window_set_accept_focus(GTK_WINDOW  (window), FALSE);
    gtk_window_set_keep_above(GTK_WINDOW  (window), TRUE);
    gtk_window_set_focus_on_map(GTK_WINDOW (window),FALSE);

    GdkWindow *gdk_window = gtk_widget_get_window(GTK_WIDGET(window));
    gdk_window_input_shape_combine_region(GDK_WINDOW(gdk_window), cairo_region_create(), 0,0);

    gtk_main();
    
    return 0;
}