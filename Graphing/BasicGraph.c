
#include <stdio.h> 
#include <stdlib.h> 

// Prints union of arr1[0..m-1] and arr2[0..n-1] 
void printUnion(int arr1[], int arr2[], int m, int n)
{
	// Before finding union, make sure arr1[0..m-1] 
	// is smaller 
	// if (m > n)
	// {
	// 	int *tempp = arr1;
	// 	arr1 = arr2;
	// 	arr2 = tempp;
	//
	// 	int temp = m;
	// 	m = n;
	// 	n = temp;
	// }
	//
	// // Now arr1[] is smaller 
	//
	// // Sort the first array and print its elements (these two 
	// // steps can be swapped as order in output is not important) 
	// sort(arr1, arr1 + m);
	// for (int i = 0; i < m; i++)
	// 	cout << arr1[i] << " ";
	//
	// // Search every element of bigger array in smaller array 
	// // and print the element if not found 
	// for (int i = 0; i < n; i++)
	// 	if (binarySearch(arr1, 0, m - 1, arr2[i]) == -1)
	// 		cout << arr2[i] << " ";
}

// An Edge struct - element/node of an adjacency list 
struct EdgeTo
{
	int dest;
	int weight;
	struct EdgeTo* next;
};

// Adjacency list struct
struct AdjList
{
	struct EdgeTo *head;
};

//Graph struct - an array of adjacency lists
//V - number of vertices in the graph
struct Graph
{
	int V;
	struct AdjList* array;
};


int  getHeaviestAdjNode(struct EdgeTo* edge)
{
	struct EdgeTo* heavy = NULL;
	
	if (edge != NULL)
	{
		heavy = edge;
		struct EdgeTo* crawl = edge->next;
		while (crawl)
		{
			heavy = heavy->weight >= crawl->weight ? heavy : crawl;
			crawl = crawl->next;
		}
		return heavy->dest;
	}
	return -1;
}

// Creates "edge" - a new node in adjacency list  
struct EdgeTo* newEdgeToNode(int dest, int weight)
{
	struct EdgeTo* new_edge =
		(struct EdgeTo*) malloc(sizeof(struct EdgeTo));
	new_edge->dest = dest;
	new_edge->weight = weight;
	new_edge->next = NULL;
	return new_edge;
}

// Creates a graph of V vertices 
struct Graph* createGraph(int V)
{
	struct Graph* graph =
		(struct Graph*) malloc(sizeof(struct Graph));
	graph->V = V;

	// Create the vertices of the graph
	// - an array of adjacency lists of size V 
	graph->array =
		(struct AdjList*) malloc(V * sizeof(struct AdjList));

	// NO Edges yet, so :
	//Initialize each adjacency list as empty by 
	// making head as NULL 
	int i;
	for (i = 0; i < V; ++i)
		graph->array[i].head = NULL;

	return graph;
}

// Adds an edge to an undirected graph 
void addEdge(struct Graph* graph, int src, int dest, int weight)
{
	// Add an edge from src to dest. A new node is 
	// added to the adjacency list of src. The node 
	// is added at the begining 
	struct EdgeTo* new_edge = newEdgeToNode(dest, weight);
	new_edge->next = graph->array[src].head;
	graph->array[src].head = new_edge;

	// Since graph is undirected, add an edge from 
	// dest to src also 
	new_edge = newEdgeToNode(src, weight);
	new_edge->next = graph->array[dest].head;
	graph->array[dest].head = new_edge;
}


// A utility function to print the adjacency list 
// representation of graph 
void printGraph(struct Graph* graph)
{
	int v;
	for (v = 0; v < graph->V; ++v)
	{
		struct EdgeTo* pCrawl = graph->array[v].head;
		printf("\n Adjacency list of vertex %d\n head ", v);
		while (pCrawl)
		{
			printf("-> %d(%d)", pCrawl->dest, pCrawl->weight);
			pCrawl = pCrawl->next;
		}
		printf("\n");
		printf("Heaviest Edge goes to %d. \n", getHeaviestAdjNode(graph->array[v].head));
		printf("\n");
	}
}

struct Graph* matchHeavyEgde(struct Graph* graph)
{
	/*
	 *	Input : Gi = (Vi, Ei) graph
		Output: Gi+1 = (Vi+1, Ei+1) graph
		1 V = Vi
		2 Ei+1 = Ei
		3 Vi+1 = Vi
		4 while V 6= ? do
			5 Choose a random node: v1 ? V
			6 Choose an edge (v1, v2) ? E which has maximum weight
			7 Remove nodes v1 and v2 from V
			8 Add a new node v = {v1, v2} to Vi+1
			9 Determine the weight of the new node: cv = cvi + cvj
			10 for every edge connecting to node v1: (v1, u) ? Ei do
				11 if (v2, u) ? E then
					12 Determine the weight of edge (v1, u): cv1,u = cv1,u + cv2,u
					13 Remove edge (v2, u) from Ei+1
				14 end
			15 end
		16 end
	 */
	while (graph && graph->array)
	{
		int  v1 = rand() % graph->V + 1;
		int  v2 = getHeaviestAdjNode(graph->array[v1].head);

	}
}

int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;

		// If the element is present at the middle itself 
		if (arr[mid] == x) return mid;

		// If element is smaller than mid, then it can only 
		// be presen in left subarray 
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		// Else the element can only be present in right subarray 
		return binarySearch(arr, mid + 1, r, x);
	}

	// We reach here when element is not present in array 
	return -1;
}

// Driver program to test above functions 
int main()
{
	// create the graph given in above fugure 
	int V = 7;
	struct Graph* graph = createGraph(V);
	addEdge(graph, 0, 1, 1);
	addEdge(graph, 0, 2, 4);
	addEdge(graph, 0, 3, 1);
	addEdge(graph, 0, 4, 1);
	addEdge(graph, 0, 5, 2);
	addEdge(graph, 0, 6, 2);
	addEdge(graph, 1, 2, 1);
	addEdge(graph, 1, 6, 4);
	addEdge(graph, 2, 3, 4);
	addEdge(graph, 3, 4, 1);
	addEdge(graph, 4, 5, 1);
	addEdge(graph, 5, 6, 1);
	addEdge(graph, 5, 7, 4);
	addEdge(graph, 7, 4, 1);


	// print the adjacency list representation of the above graph 
	printGraph(graph);

	return 0;
}
