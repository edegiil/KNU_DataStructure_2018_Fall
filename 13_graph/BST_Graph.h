#include "ADT_linked_list.h"

typedef struct graph{
    LIST* vertex_list;
}GRAPH;

typedef struct vertex{
    int data;
    LIST* arc_list;
}VERTEX;

typedef struct arc{
    VERTEX* to_vertex;
}ARC;

GRAPH* create_graph();
bool graph_vertex_insertion(GRAPH* graph, int data);
int find_vertex(LIST* list, void* search_data);
bool graph_arc_insertion(GRAPH* graph, int from, int to);