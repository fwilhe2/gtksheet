#include <stdlib.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <gdk/gdkkeysyms.h>
#include <glib.h>
#include <string.h>
#include "gtksheet.h"

static void
activate(GtkApplication *app, gpointer user_data)
{
  GtkWidget *window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Spreadsheet");
  gtk_window_set_default_size(GTK_WINDOW(window), 1024, 768);

  GtkWidget *cellAddress = gtk_label_new("foo");
  GtkWidget *formula = gtk_data_entry_new();

  GtkWidget *sheet = gtk_sheet_new(20, 20, "Sheet 1");
  //   GTK_SHEET_SET_FLAGS(sheet, GTK_SHEET_AUTORESIZE);

  GtkWidget *box_spreadsheet = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
  gtk_box_set_homogeneous(GTK_BOX(box_spreadsheet), FALSE);

  GtkWidget *box_toolbar = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
  gtk_box_set_homogeneous(GTK_BOX(box_spreadsheet), TRUE);

  gtk_container_add(GTK_BOX(box_toolbar), cellAddress);
  gtk_container_add(GTK_BOX(box_toolbar), formula);

  gtk_container_add(GTK_BOX(box_spreadsheet), box_toolbar);
  gtk_container_add(GTK_BOX(box_spreadsheet), sheet);

  gtk_container_add(GTK_CONTAINER(window), box_spreadsheet);
  gtk_widget_show_all(window);
}

int main(int argc, char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}