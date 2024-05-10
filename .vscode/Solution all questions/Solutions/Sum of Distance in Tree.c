//#include <stdio.h>
//#include <stdlib.h>
//
//// Sites i used : https://www.geeksforgeeks.org/c-program-for-inserting-a-node-in-a-linked-list/
//// https://www.programiz.com/dsa/graph-adjacency-list
//
//struct Node //This is how I'm represent the value of the node and pointer to the next.
//{
//    int val;
//    struct Node* next;
//};
//
//struct Graph //This is how i will use the graph to sum distance for each tree.
//{
//    struct Node** adjList; //Array of pointer where each index corresponds to a node in the graph, and 
//    //  each pointer points to the first node in the adjacency list of that node
//    int* count; //This is Array for store the count of nodes in the subtree rooted at each node.
//    int* total; //An array to store the total distance sum of each node in the tree.
//};
//
//struct Node* createNode(int val) //for making new node use from geeksforgeeks.
//{
//    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//    newNode->val = val;
//    newNode->next = NULL;
//    return newNode;
//}
//
//void addEdge(struct Graph* graph, int src, int dest)// we make node(src) and node(dest)
//// and connect them to adjList array or example, if the edge is [0,1], then src is 0 and dest is 1. Two nodes 
//// will be created, one for node 1 and one for node 0.
//{
//    struct Node* newNode = createNode(dest);
//    newNode->next = graph->adjList[src];
//    graph->adjList[src] = newNode;
//
//    newNode = createNode(src);
//    newNode->next = graph->adjList[dest];
//    graph->adjList[dest] = newNode;
//}
//
//struct Graph* createGraph(int n, int** edges, int edgesSize)//Creating the graph.
//{
//    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));///Allocate the initial struct of graph
//    //This is contain the adjlist pointer array the count and total.
//    graph->adjList = (struct Node**)malloc(n * sizeof(struct Node*));//Make adjlist pointer array of size n.
//    // n is the num of nodes.
//    graph->count = (int*)malloc(n * sizeof(int));
//    //array within the graph structure. It allocates space for n integers, each representing the count of 
//    //nodes in the subtree rooted at a particular node.
//    graph->total = (int*)malloc(n * sizeof(int));
//
//    for (int i = 0; i < n; i++)//Initializes each element of the adjacency list, count, and total arrays.
//    {
//        graph->adjList[i] = NULL;
//        graph->count[i] = 1;
//        graph->total[i] = 0;
//    }
//
//    for (int i = 0; i < edgesSize; i++)//for creating nodes for edges and connect to adjacency list.
//    {
//        addEdge(graph, edges[i][0], edges[i][1]);
//    }
//
//    return graph;
//}
//
//void dfs(struct Graph* graph, int node, int parent)// first dfs will fill the count and total arrays but we will
////another dfs becuase total now dont have the sum of distance with all nodes he had only with subtrees.
//{
//    struct Node* temp = graph->adjList[node];
//    while (temp != NULL) {
//        if (temp->val != parent)
//        {
//            dfs(graph, temp->val, node);
//            graph->count[node] += graph->count[temp->val];
//            graph->total[node] += graph->total[temp->val] + graph->count[temp->val];
//        }
//        temp = temp->next;
//    }
//}
//
//void dfs2(struct Graph* graph, int node, int parent, int n)//here we made the full total array.
//{
//    struct Node* temp = graph->adjList[node];
//    while (temp != NULL) {
//        if (temp->val != parent)
//        {
//            graph->total[temp->val] = graph->total[node] - graph->count[temp->val] + n - graph->count[temp->val];
//            dfs2(graph, temp->val, node, n);
//        }
//        temp = temp->next;
//    }
//}
//
//int* sumOfDistancesInTree(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize)
//{
//    struct Graph* graph = createGraph(n, edges, edgesSize);// Make the graph with adjlist count and total array.
//
//    dfs(graph, 0, -1);//first dfs for array count and total (only subtree here so we need second dfs)
//    dfs2(graph, 0, -1, n);//complete the total array that have the answer.
//
//    int* result = (int*)malloc(n * sizeof(int));
//    for (int i = 0; i < n; i++)
//    {
//        result[i] = graph->total[i]; // Copy the answers to result array from total array that located in graph
//    }
//
//    *returnSize = n;
//    return result; // Send the array of distance.
//}
