#include <gtk/gtk.h>
#include "ga.h"

gboolean draw(GtkWidget *widget, cairo_t *cr, gpointer data);
gboolean draw_plan(GtkWidget *widget, cairo_t *cr, gpointer data);
gboolean draw_dot(GtkWidget *widget, cairo_t *cr, gpointer data, Ponto p);
gboolean draw_line(GtkWidget *widget, cairo_t *cr, gpointer data, Reta r);
gboolean draw_circle(GtkWidget *widget, cairo_t *cr, gpointer data, Circle c);

gint main(int argc,char *argv[]) {
    GtkWidget *window, *drawing_area;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 1800, 850);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    drawing_area = gtk_drawing_area_new();
    gtk_container_add(GTK_CONTAINER(window), drawing_area);
    g_signal_connect(G_OBJECT(drawing_area), "draw", G_CALLBACK(draw), NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

gboolean draw(GtkWidget *widget, cairo_t *cr, gpointer data) {    
    double start, step, end, x;
    int filtro;
    Ponto a, b, c;
    Circle o;
    Reta r;

    a.x = 300;
    a.y = 155.25;

    b.x = 200;
    b.y = -350.5;

    r.m = 2;
    r.k = 100;

    //printf("Insira dois pontos no formato \"X Y\"\n");
    //scanf("%lf%lf", &a.x, &a.y);
    //scanf("%lf%lf", &b.x, &b.y);

    //printf("Insira uma equação da reta no fomato \"m k\"\n");
    //scanf("%lf%lf", &r.m, &r.k);

    //printf("Insira um início, um passo e um final desejado\n");
    //scanf("%lf%lf%lf", &start, &step, &end);

    draw_plan(widget, cr, data);
    draw_dot(widget, cr, data, a);
    draw_dot(widget, cr, data, b);
    draw_line(widget, cr, data, r);

    start = -599.9;
    step = 0.1;
    end = 599.9;
    for(x = start, filtro = 0; x < end; x += step, filtro++) {
        c = novoPonto(r, x);
        o = novaCircunferencia(a, b, c);
        draw_dot(widget, cr, data, o.centro);
        if(filtro%100 == 0 || filtro == 0) draw_circle(widget, cr, data, o);
    }

    return FALSE;
}

gboolean draw_plan(GtkWidget *widget, cairo_t *cr, gpointer data) {
    guint width, height;

    width = gtk_widget_get_allocated_width(widget);
    height = gtk_widget_get_allocated_height(widget);

    cairo_move_to (cr, 0, height/2.0);
    cairo_line_to (cr, width, height/2.0);
    cairo_move_to (cr, width/2.0, height);
    cairo_line_to (cr, width/2.0, 0);

    cairo_set_source_rgb (cr, 1, 0, 0);
    cairo_set_line_width (cr, 5);

    cairo_stroke (cr);

    return FALSE;
}

gboolean draw_dot(GtkWidget *widget, cairo_t *cr, gpointer data, Ponto p) {
    guint width, height;
    Ponto t;

    width = gtk_widget_get_allocated_width(widget);
    height = gtk_widget_get_allocated_height(widget);
    t.x = (width/2.0) + p.x;
    t.y = (height/2.0) - p.y;


    cairo_arc(cr, t.x, t.y, 1, 0, 2*G_PI);

    cairo_set_source_rgb (cr, 0, 0, 1); 
    cairo_set_line_width(cr, 5);

    cairo_stroke(cr);

    return FALSE;
}

gboolean draw_line(GtkWidget *widget, cairo_t *cr, gpointer data, Reta r) {
    guint width, height;
    Ponto inicio, fim;

    width = gtk_widget_get_allocated_width(widget);
    height = gtk_widget_get_allocated_height(widget);
    inicio = novoPonto(r, width);
    fim = novoPonto(r, -width);

    cairo_move_to (cr, width/2.0 + inicio.x, height/2.0 - inicio.y);
    cairo_line_to (cr, width/2.0 + fim.x, height/2.0 - fim.y);

    cairo_set_source_rgb (cr, 1, 0, 0);
    cairo_set_line_width (cr, 3);

    cairo_stroke (cr);

    return FALSE;
}

gboolean draw_circle(GtkWidget *widget, cairo_t *cr, gpointer data, Circle c) {
    guint width, height;

    width = gtk_widget_get_allocated_width(widget);
    height = gtk_widget_get_allocated_height(widget);

    cairo_arc(cr, width/2.0 + c.centro.x, height/2.0 - c.centro.y, c.raio, 0, 2*G_PI);

    cairo_set_source_rgb (cr, 0, 1, 0);
    cairo_set_line_width(cr, 1.5);

    cairo_stroke(cr);

    return FALSE;
}