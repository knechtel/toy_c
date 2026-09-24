#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    /* =========================
       JANELA
       ========================= */

    GtkWidget *window;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(
        GTK_WINDOW(window),
        "Lista GTK"
    );

    gtk_window_set_default_size(
        GTK_WINDOW(window),
        400,
        300
    );

    gtk_container_set_border_width(
        GTK_CONTAINER(window),
        20
    );

    g_signal_connect(
        window,
        "destroy",
        G_CALLBACK(gtk_main_quit),
        NULL
    );


    /* =========================
       CONTAINER
       ========================= */

    GtkWidget *box;

    box = gtk_box_new(
        GTK_ORIENTATION_VERTICAL,
        10
    );

    gtk_container_add(
        GTK_CONTAINER(window),
        box
    );


    /* =========================
       LABEL
       ========================= */

    GtkWidget *label;

    label = gtk_label_new("Lista de usuários:");

    gtk_box_pack_start(
        GTK_BOX(box),
        label,
        FALSE,
        FALSE,
        0
    );


    /* =========================
       LIST STORE
       ========================= */

    GtkListStore *store;

    store = gtk_list_store_new(
        1,
        G_TYPE_STRING
    );


    /* =========================
       ADICIONANDO ITENS
       ========================= */

    GtkTreeIter iter;

    gtk_list_store_append(
        store,
        &iter
    );

    gtk_list_store_set(
        store,
        &iter,
        0,
        "Maiquel",
        -1
    );


    gtk_list_store_append(
        store,
        &iter
    );

    gtk_list_store_set(
        store,
        &iter,
        0,
        "João",
        -1
    );


    gtk_list_store_append(
        store,
        &iter
    );

    gtk_list_store_set(
        store,
        &iter,
        0,
        "Maria",
        -1
    );


    gtk_list_store_append(
        store,
        &iter
    );

    gtk_list_store_set(
        store,
        &iter,
        0,
        "Carlos",
        -1
    );


    /* =========================
       TREE VIEW
       ========================= */

    GtkWidget *tree;

    tree = gtk_tree_view_new_with_model(
        GTK_TREE_MODEL(store)
    );


    /* =========================
       COLUNA
       ========================= */

    GtkCellRenderer *renderer;

    renderer = gtk_cell_renderer_text_new();

    GtkTreeViewColumn *column;

    column = gtk_tree_view_column_new_with_attributes(
        "Nome",
        renderer,
        "text",
        0,
        NULL
    );

    gtk_tree_view_append_column(
        GTK_TREE_VIEW(tree),
        column
    );


    /* =========================
       SCROLL
       ========================= */

    GtkWidget *scroll;

    scroll = gtk_scrolled_window_new(
        NULL,
        NULL
    );

    gtk_widget_set_vexpand(
        scroll,
        TRUE
    );

    gtk_container_add(
        GTK_CONTAINER(scroll),
        tree
    );

    gtk_box_pack_start(
        GTK_BOX(box),
        scroll,
        TRUE,
        TRUE,
        0
    );


    /* =========================
       MOSTRAR
       ========================= */

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
