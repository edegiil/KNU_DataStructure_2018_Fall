#include "BST_Graph.h"

GRAPH* create_graph(){
    GRAPH* graph = (GRAPH*)malloc(sizeof(GRAPH));
    graph->vertex_list = create_list();
    return graph;   
}

bool graph_vertex_insertion(GRAPH* graph, int data){
    VERTEX* new_vertex = (VERTEX*)malloc(sizeof(VERTEX));
    new_vertex->data = data;
    new_vertex->arc_list = create_list();

    int vertex_loc = find_vertex(graph->vertex_list, new_vertex);
    if(vertex_loc != -1){
        free(new_vertex);
        return false;
    }
    return node_insertion(graph->vertex_list, graph->vertex_list->count, new_vertex);
}

int find_vertex(LIST* list, void* serch_data){
    list->pos = list->front;
    int iteration = 0;
    while(list->pos!=NULL){
        VERTEX* left = (VERTEX*)(list->pos->data_ptr);
        VERTEX* right = (VERTEX*)serch_data;

        if(left->data == right->data){
            return iteration;
        }
        list->pos = list->pos->next;
        iteration++;
    }
    return -1;
}

bool graph_arc_insertion(GRAPH* graph, int from, int to){
    VERTEX vertex1;
    vertex1.data = from;
    vertex1.arc_list = NULL;

    int vertex_loc = find_vertex(graph->vertex_list, &vertex1);
    if(vertex_loc == -1){
        printf("from vertex %c not found", (char)from);
        return false;
    }

    VERTEX* from_vertex = (VERTEX*)get_data_at(graph->vertex_list, vertex_loc);

    VERTEX vertex2;
    vertex2.data = to;
    vertex2.arc_list = NULL;

    vertex_loc = find_vertex(graph->vertex_list, &vertex2);
    if(vertex_loc == -1){
        printf("to vertex %c not found", (char)to);
        return false;
    }

    VERTEX* to_vertex = (VERTEX*)get_data_at(graph->vertex_list, vertex_loc);

    ARC* new_arc = (ARC*)malloc(sizeof(ARC));
    new_arc->to_vertex = to_vertex;

    return node_insertion(from_vertex->arc_list, from_vertex->arc_list->count, new_arc);
}