#include <stdlib.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <gdk/gdkkeysyms.h>
#include <glib.h>
#include <string.h>
#include "gtksheet.h"

void on_entry_changed(GtkEntry *entry, gpointer user_data)
{
    const gchar *formula = gtk_entry_get_text(entry);
    printf("Formula: %s\n", formula);
    fflush(stdout);
}

static void
activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Spreadsheet");
    gtk_window_set_default_size(GTK_WINDOW(window), 1024, 768);

    // Create the main grid layout
    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Create the label
    GtkWidget *label = gtk_label_new("R1C1");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 1, 1);

    // Create the formula entry
    GtkWidget *entry = gtk_entry_new();
    g_signal_connect(entry, "changed", G_CALLBACK(on_entry_changed), NULL);
    gtk_grid_attach(GTK_GRID(grid), entry, 1, 0, 1, 1);

    // Create the spreadsheet area
    GtkWidget *spreadsheet = gtk_sheet_new(20, 20, "Sheet 1");
    gtk_widget_set_hexpand(spreadsheet, TRUE);
    gtk_widget_set_vexpand(spreadsheet, TRUE);
    gtk_grid_attach(GTK_GRID(grid), spreadsheet, 0, 1, 2, 1);

    gtk_widget_show_all(window);
}

int main(int argc, char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}