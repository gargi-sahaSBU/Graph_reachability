#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
struct LL {
    void *node_ref;
    struct LL *next;
};
typedef struct LL LListNode;

typedef struct {
    int key;
    LListNode *dom_e;
    int in_r;
    int in_s;
    int in_t;
}Vertex;



int main() {
    FILE *fp,*output;
    LListNode *temp_node;
    LListNode *W ,*S, *R, *parse_lw,*parse_rw,*Wtemp;
    Vertex *array_v[502];
    Vertex *temp_v,*temp_v2;
    LListNode *ran_v,*new;
    int v1,v2=1;
    int source;
    int i;
    clock_t start, end;
    double cpu_time_used;
    output = fopen("Coutput","a");

    for(i=0;i<502;i++) {
        array_v[i] = NULL;
    }
    fp = fopen("files/C_reach.in.1000", "r");
    start = clock();
    while(1) {
        fscanf(fp,"%d %d",&v1,&v2);

        if(v2 == 0) {
            source = v1;
            break;
        }

        if(array_v[v1] == NULL) {
            array_v[v1] = (Vertex *)malloc(sizeof(Vertex));
            array_v[v1]->key = v1;
            array_v[v1]->dom_e = NULL;
            array_v[v1]->in_s = 0;
            array_v[v1]->in_r = 0;
            array_v[v1]->in_t = 0;
        }
        if(array_v[v2] == NULL) {
            array_v[v2] = (Vertex *)malloc(sizeof(Vertex));
            array_v[v2]->key = v2;
            array_v[v2]->dom_e = NULL;
            array_v[v2]->in_s = 0;
            array_v[v2]->in_r = 0;
            array_v[v2]->in_t = 0;
        }

        if(array_v[v1]->dom_e == NULL) {
            array_v[v1]->dom_e = (LListNode *)malloc(sizeof(LListNode));
            array_v[v1]->dom_e->next = NULL;
            array_v[v1]->dom_e->node_ref = array_v[v2];
        }
        else {
            temp_node = array_v[v1]->dom_e;
            array_v[v1]->dom_e = (LListNode *)malloc(sizeof(LListNode));
            array_v[v1]->dom_e->next = temp_node;
            array_v[v1]->dom_e->node_ref = array_v[v2];
        }

    }

    W = (LListNode *)malloc(sizeof(LListNode));
    W->node_ref = array_v[source];
    W->next = NULL;
    array_v[source]->in_s = 1;

    //while exists x in W
    while(W != NULL) {
        temp_v = (Vertex *)W->node_ref;

        ran_v = temp_v->dom_e;

        //for y in e{x}
        while(ran_v != NULL) {
            temp_v2 = (Vertex *)ran_v->node_ref;
            //if y not in t
            if(temp_v2->in_t != 1) {
                //if y not in r and y not in s
                if ((temp_v2->in_r != 1) && (temp_v2->in_s != 1)) {

                    //w add y
                    new = (LListNode *)malloc(sizeof(LListNode));
                    new->node_ref = temp_v2;
                    new->next = NULL;
                    Wtemp = W;
                    while(Wtemp->next != NULL) {
                        Wtemp = Wtemp->next;
                    }
                    Wtemp->next = new;

                }
                //t add y
                temp_v2->in_t = 1;
            }
            ran_v = ran_v->next;
        }
        //if x in t or x in s
        if((temp_v->in_t == 1) || (temp_v->in_s == 1)) {
            //w del x
            W->node_ref = NULL;
        }
        //r add x
        temp_v->in_r = 1;

        W= W->next;
    }


    for(i = 0 ; i < 502; i++) {
        if(array_v[i] != NULL){
            temp_v = array_v[i];
            if(temp_v->in_r == 1) {
                fprintf(output,"%d ",temp_v->key);
            }
        }

    }
    fprintf(output,"\n");
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    fprintf(output,"%f\n",cpu_time_used);


    for(i=0;i<502;i++) {
        free(array_v[i]);
    }
    fclose(output);
    fclose(fp);
    return 0;
}