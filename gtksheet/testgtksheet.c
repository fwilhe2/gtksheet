#include <stdlib.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <gdk/gdkkeysyms.h>
#include <glib.h>
#include <string.h>
#include "gtksheet.h"

static void
activate(GtkApplication *app,
         gpointer user_data)
{
  GtkWidget *window;
  GtkWidget *sheet;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Window");
  gtk_window_set_default_size(GTK_WINDOW(window), 1024, 768);

  sheet = gtk_sheet_new(20, 20, "Edit table");
//   GTK_SHEET_SET_FLAGS(sheet, GTK_SHEET_AUTORESIZE);

  gtk_container_add (GTK_CONTAINER (window), sheet);
  gtk_widget_show_all(window);
}

int main(int argc,
         char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}