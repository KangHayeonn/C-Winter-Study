## πκ·Έλνμ νμ(Graph_Search)
##### λ΄λΉμ : λ°μ£Όν
<br>

### πκ·Έλνλ?
![image](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FcjbjPd%2FbtqKgF6OzSD%2FU0a7BKCpfJlhx1iJzwsEy1%2Fimg.png) 
<br>
κ·Έλνλ μ μ κ³Ό κ°μ μΌλ‘ μ΄λ£¨μ΄μ§ μλ£κ΅¬μ‘°μλλ€. μ ννλ μ μ (Vertex)κ°μ κ΄κ³λ₯Ό νννλ μ‘°μ§λλΌκ³  λ³Όμλ μκ² μ΅λλ€. κ·Έλ°λ©΄μμ νΈλ¦¬λ κ·Έλνμ μΌμ’μΈ μμλλ€. λ€λ§ νΈλ¦¬μλ λ¬λ¦¬ κ·Έλνλ μ μ λ§λ€ κ°μ μ΄ μμμλ μκ³  μμμλ μμΌλ©° λ£¨νΈ λΈλ, λΆλͺ¨μ μμμ΄λΌλ κ°λμ΄ μ‘΄μ¬νμ§ μμ΅λλ€. λν κ·Έλνλ λ€νΈμν¬ λͺ¨λΈ μ¦, κ°μ²΄μ μ΄μ λν κ΄κ³λ₯Ό λνλ΄λ μ μ°ν λ°©μμΌλ‘ μ΄ν΄ν  μ μμ΅λλ€. μ€μνμμ λ€μν μλ₯Ό κ·Έλνλ‘ ννν  μ μμ΅λλ€. λνμ μΌλ‘ μ§νμ²  λΈμ λ, λμ¬μ λλ‘λ±μ΄ μμ΅λλ€. μ΄λ°μμΌλ‘ νμ©ν  μ μλ λ°©λ²μ΄ λ§κΈ°μ λ¬Έμ λ λ€μνκ² μΆμ λ₯Ό ν  μ μμ΅λλ€. κ·Έλνλ μκ³ λ¦¬μ¦μμ κ΅μ₯ν λ§μ΄ μ¬μ©λ©λλ€. νΉν κ·Έλνλ₯Ό μννλ λ°©μμΈ DFSμ BFSλ₯Ό μ μμλμ΄μΌ ν©λλ€. <br>
<br>


### πκ·Έλνμμ μ¬μ©νλ μ©μ΄
<br>
μ μ (vertice) : λΈλ(node)λΌκ³ λ νλ©° μ μ μλ λ°μ΄ν°κ° μ μ₯λ©λλ€. (0, 1, 2, 3)<br>
κ°μ (edge): λ§ν¬(arcs)λΌκ³ λ νλ©° λΈλκ°μ κ΄κ³λ₯Ό λνλλλ€.<br>
μΈμ  μ μ (adjacent vertex) : κ°μ μ μν΄ μ°κ²°λ μ μ μΌλ‘ μμμ (μ μ 0κ³Ό μ μ 1μ μΈμ  μ μ )<br>
λ¨μ κ²½λ‘(simple-path): κ²½λ‘ μ€ λ°λ³΅λλ μ μ μ΄ μλκ², κ°μ κ°μ μ μλκ°μ§ μλ κ²½λ‘<br>
μ°¨μ(degree): λ¬΄λ°©ν₯ κ·Έλνμμ νλμ μ μ μ μΈμ ν μ μ μ μ (μ μ  0μ μ°¨μλ 3)<br>
μ§μΆ μ°¨μ(out-degree) : λ°©ν₯κ·Έλνμμ μ¬μ©λλ μ©μ΄λ‘ ν λΈλμμ μΈλΆλ‘ ν₯νλ κ°μ μ μλ₯Ό λ»ν©λλ€.<br>
μ§μμ°¨μ(in-degree) : λ°©ν₯κ·Έλνμμ μ¬μ©λλ μ©μ΄λ‘ μΈλΆ λΈλμμ λ€μ΄μ€λ κ°μ μ μλ₯Ό λ»ν©λλ€.<br>
<br>

### πκ·Έλν κ΅¬ν λ°©λ² 
<br>
κ·Έλνλ₯Ό κ΅¬ννλ λ°©λ²μλ 1.μΈμ νλ ¬(Adjacency Materix)μ 2.μΈμ λ¦¬μ€νΈ(Adjacency List)λ°©μμ΄ μμ΅λλ€. <br>
λκ°μ κ΅¬ν λ°©μμ κ°κ°μ μλ°λ μ₯λ¨μ μ κ°μ§κ³  μλλ° λλΆλΆ μΈμ λ¦¬μ€νΈ νμμ λ§μ΄λ€ μ¬μ©ν©λλ€.<br>
<br>
<br>
<br>

### 1.μΈμ νλ ¬ λ°©μ 
![image](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2F7RFhy%2FbtqKkOhoYiE%2FSE3IQP2q0g3xd34EQZkjM1%2Fimg.png)
<br>
μΈμ νλ ¬μ κ·Έλνμ λΈλλ₯Ό 2μ°¨μ λ°°μ΄λ‘ λ§λ  κ²μλλ€. μμ±λ λ°°μ΄μ λͺ¨μμ 1, 2, 3, 4, 5, 6μ μ μ μ μ°κ²°νλ λΈλμ λ€λ₯Έ λΈλλ€μ΄ μΈμ  μ μ μ΄λΌλ©΄ 1, μλλ©΄ 0μ λ£μ΄μ€λλ€.<br>
<br>
<br>

#### μΈμ νλ ¬ μ₯μ 
1. 2μ°¨μ λ°°μ΄ μμ λͺ¨λ  μ μ λ€μ κ°μ  μ λ³΄λ₯Ό λ΄κΈ° λλ¬Έμ λ°°μ΄μ μμΉλ₯Ό νμΈνλ©΄ λ μ μ λν μ°κ²° μ λ³΄λ₯Ό μ‘°νν  λ O(1) μ μκ° λ³΅μ‘λλ©΄ κ°λ₯ν©λλ€. <br>
2. κ΅¬νμ΄ λΉκ΅μ  κ°νΈν©λλ€.<br>
<br>

#### μΈμ νλ ¬ λ¨μ 
1. λͺ¨λ  μ μ μ λν΄ κ°μ  μ λ³΄λ₯Ό λμν΄μΌ νλ―λ‘ O(nΒ²) μ μκ°λ³΅μ‘λκ° μμλ©λλ€.<br>
2. λ¬΄μ‘°κ±΄ 2μ°¨μ λ°°μ΄μ΄ νμνκΈ°μ νμ μ΄μμ κ³΅κ°μ΄ λ­λΉλ©λλ€.<br>
<br>
<br>
<br>

#### 2.μΈμ λ¦¬μ€νΈ λ°©μ 
![image](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FNlh1G%2FbtqKicb2Wub%2FsHWVSS6bn2FZdijEJVR2r1%2Fimg.png)
<br>
μΈμ λ¦¬μ€νΈλ κ·Έλνμ λΈλλ€μ λ¦¬μ€νΈλ‘ νννκ²μλλ€. μ£Όλ‘ μ μ μ λ¦¬μ€νΈ λ°°μ΄μ λ§λ€μ΄ κ΄κ³λ₯Ό μ€μ ν΄μ€μΌλ‘μ¨ κ΅¬νν©λλ€. 
<br>
<br>

#### μΈμ λ¦¬μ€νΈ μ₯μ 
1. μ μ λ€μ μ°κ²° μ λ³΄λ₯Ό νμν  λ O(n) μ μκ°μ΄λ©΄ κ°λ₯ν©λλ€. (n: κ°μ μ κ°―μ)
2. νμν λ§νΌμ κ³΅κ°λ§ μ¬μ©νκΈ°λλ¬Έμ κ³΅κ°μ λ­λΉκ° μ μ΅λλ€.
<br>

#### μΈμ λ¦¬μ€νΈ λ¨μ 
1. νΉμ  λ μ μ΄ μ°κ²°λμλμ§ νμΈνλ €λ©΄ μΈμ νλ ¬μ λΉν΄ μκ°μ΄ μ€λ κ±Έλ¦½λλ€. (λ°°μ΄λ³΄λ€ search μλλλ¦Ό)
2. κ΅¬νμ΄ λΉκ΅μ  μ΄λ ΅μ΅λλ€.
<br>
<br>
<br>

### πλ€μν κ·Έλνμ μ’λ₯ 
κ·Έλνλ κ΅¬νλμ΄μ§ νΉμ±μ λ°λΌ μ¬λ¬κ°μ§ μ’λ₯λ‘ λλμ΄μ§λλ€. λνμ μΈ κ·Έλνμ μ νμ μλμ κ°μ΅λλ€.
<br>
<br>
<br>

#### 1.λ¬΄λ°©ν₯κ·Έλν
![image](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2F0ZsjG%2FbtqKjcbPzFp%2FEmai2Mc2IWMIAENKHr4Is1%2Fimg.png)
<br>
λ¬΄λ°©ν₯ κ·Έλνλ λ μ μ μ μ°κ²°νλ κ°μ μ λ°©ν₯μ΄ μλ κ·Έλνμλλ€.
<br>
<br>

#### 2.λ°©ν₯κ·Έλν 
![image](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Fbvvxel%2FbtqKkPUXTtY%2FpsdErjeixg2KkpZWHc9NqK%2Fimg.png)
<br>
λ°©ν₯ κ·Έλνλ λ μ μ μ μ°κ²°νλ κ°μ μ λ°©ν₯μ΄ μ‘΄μ¬νλ κ·Έλνμλλ€. κ°μ μ λ°©ν₯μΌλ‘λ§ μ΄λν  μ μμ΅λλ€. 
<br>
<br>

#### 3.κ°μ€μΉκ·Έλν 
![image](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FBVFRy%2FbtqKopgFBy3%2FSlXKIsNr2avTAKIyLnwuvk%2Fimg.png)
<br>
κ°μ€μΉ κ·Έλνλ λ μ μ μ μ΄λν λ λΉμ©μ΄ λλ κ·Έλνμλλ€.
<br>
<br>

#### 4.μμ κ·Έλν
![image](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FmPtuW%2FbtqKqyqTexj%2FUDBayShMmL3p8LGDl25uR1%2Fimg.png)
<br>
μμ  κ·Έλνλ λͺ¨λ  μ μ μ΄ κ°μ μΌλ‘ μ°κ²°λμ΄ μλ κ·Έλνμλλ€.
<br>
<br>

### πκ·Έλνμ νμ 
![image](https://blog.kakaocdn.net/dn/cFgEJ6/btqKmoJkq5a/pwm3O8T4rERuL4wSTrkgnK/img.gif)
<br>
μ²« μ μ μμλΆν° κ·Έλνμ μ‘΄μ¬νλ λͺ¨λ  μ μ λ€μ λͺ¨λ νλ²μ© λ°©λ¬Ένλ κ²μ κ·Έλν νμμ΄λΌκ³  ν©λλ€. κ·Έλν νμμ λ°©λ²μ κΉμ΄ μ°μ± νμ(DFS) λ°©μκ³Ό λλΉ μ°μ  νμ(BFS)λ°©μμ΄ μμ΅λλ€.
<br>
<br>
<br>

#### 1.κΉμ΄ μ°μ νμ(DFS)
κΉμ΄ μ°μ νμ DFSλ κ° μ μλ λ§νΌ μ΅λν κΉμ΄ κ°κ³ , λ μ΄μ κ° κ³³μ΄ μλ€λ©΄ μ΄μ  μ μ μΌλ‘ λμκ°λ λ°©μμΌλ‘ κ·Έλνλ₯Ό μννλ λ°©μμλλ€. κ°λ¨ν μ¬κ·νΈμΆμ μ¬μ©νμ¬ κ΅¬ννκ±°λ μ€νμ μ¬μ©νμ¬ κ΅¬νν©λλ€. 
<br>
<br>

#### 2.λμ΄ μ°μ νμ(BFS)
λμ΄ μ°μ νμ BFSλ μμμ μ μ λ°©λ¬Έν ν μμ μ μ μ μΈμ ν λͺ¨λ  μ μ μ λ°©λ¬Έν ν μμ μ μ μ μΈμ ν λͺ¨λ  μ μ λ€μ μ°μ λ°©λ¬Ένλ λ°©λ²μλλ€. μΌλ°μ μΌλ‘ QUEUEλ₯Ό μ¬μ©ν΄μ μ§κΈ μμΉμμ κ° μ μλ κ²λ€μ λͺ¨λ νμ λ£λ λ°©μμΌλ‘ κ΅¬νν©λλ€.
<br>
<br>
<br>


### πCλ‘ κ΅¬νν μΈμ νλ ¬ κ·Έλν μ½λ
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct GraphType{
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;


// κ·Έλν μ΄κΈ°ν
void init(GraphType* g){
    int r,c;
    g->n=0;
    for(r=0;r<MAX_VERTICES;r++)
        for(c=0;c<MAX_VERTICES;c++)
           g->adj_mat[r][c]=0;
}


//μ μ  μ½μ
void insert_vertex(GraphType* g,int v){
    if (((g->n)+1)>MAX_VERTICES){
        fprintf(stderr,"overflow");
        return;
    }
    g->n++;
}

//κ°μ  μ½μ
void insert_edge(GraphType* g,int start,int end){
    if(start>=g->n||end>=g->n){
        fprintf(stderr,"vertex key error");
        return;
    }
    g->adj_mat[start][end]=1;
    g->adj_mat[end][start]=1;
}

// μΈμ  νλ ¬ μΆλ ₯ ν¨μ
void print_adj_mat(GraphType* g){
    for(int i=0;i<g->n;i++){
        for(int j=0;j<g->n;j++){
            printf("%2d",g->adj_mat[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    GraphType *g;
    g=(GraphType *)malloc(sizeof(GraphType));
    init(g);
    for(int i=0;i<4;i++)
       insert_vertex(g,i);
    insert_edge(g,0,1);
    insert_edge(g,0,2);
    insert_edge(g,0,3);
    insert_edge(g,1,2);
    insert_edge(g,2,3);
    print_adj_mat(g);
    
    free(g);
}
```
<br>
<br>

### πCλ‘ κ΅¬νν μΈμ λ¦¬μ€νΈ κ·Έλν μ½λ
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct GraphNode{
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType{
    int n;
    GraphNode* adj_list[MAX_VERTICES];
} GraphType;

void init(GraphType* g){
    int v;
    g->n=0;
    for(v=0;v<MAX_VERTICES;v++)
        g->adj_list[v]=NULL;
}

void insert_vertex(GraphType* g,int v){
    if(((g->n)+1)>MAX_VERTICES){
        fprintf(stderr,"overflow");
        return;
    }
    g->n++;
}

void insert_edge(GraphType* g,int u,int v){
    GraphNode* node;
    if(u>=g->n||v>=g->n){
        fprintf(stderr,"vertex index error");
        return;
    }
    node= (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex=v;
    node->link=g->adj_list[u];
    g->adj_list[u]=node;
}

void print_adj_list(GraphType* g){
    for(int i=0;i<g->n;i++){
        GraphNode* p=g->adj_list[i];
        printf("μ μ  %dμ μΈμ  λ¦¬μ€νΈ",i);
        while(p!=NULL){
            printf("->%d",p->vertex);
            p=p->link;
        }
        printf("\n");
    }
}

int main()
{
    GraphType *g;
    g=(GraphType*)malloc(sizeof(GraphType));
    init(g);
    for(int i=0;i<4;i++)
        insert_vertex(g,i);
    insert_edge(g,0,1);
    insert_edge(g,1,0);
    insert_edge(g,0,2);
    insert_edge(g,2,0);
    insert_edge(g,0,3);
    insert_edge(g,3,0);
    insert_edge(g,1,2);
    insert_edge(g,2,1);
    insert_edge(g,2,3);
    insert_edge(g,3,2);
    print_adj_list(g);

    free(g);

    return 0;
}
```
<br>
<br>
μ΄λ‘  μΆμ² : https://coding-factory.tistory.com/610
<br>
μ½λ μΆμ² : https://velog.io/@kysung95/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-C%EB%A1%9C-%EA%B7%B8%EB%9E%98%ED%94%84%EB%A5%BC-%EB%A7%8C%EB%93%A4%EC%9E%90
