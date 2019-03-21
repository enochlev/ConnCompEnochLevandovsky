//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
//Data Modifier: Enoch Levandovsky
//Completed:
//I was working on a kruskal algorithm from scratch, then later //
//found out I needed only connected components. 
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
#pragma once
#include <iostream>
using namespace std;

class Node
{
private:
	


	int checkednodes[100];//all nodes insude box...no sort or squence
	int numberofnodesinsidebox = 0;
	bool visited[100];//true false of node A
	int adjacentNodes[100][100];
	int adjacentNodesDistances[100][100];
	int numberofadjacentnodes[100];




public:
	

	void setupSize(int size)
	{
		int counter = 0;
		while (counter < size)
		{

			visited[counter] = false;
			numberofadjacentnodes[counter] = 0;
			counter++;
		}
		
	}


	void feedNode(int nodeyourfeeding ,int nodetofeed, int distanceaway)
	{
		
		adjacentNodes[nodeyourfeeding][numberofadjacentnodes[nodeyourfeeding]] = nodetofeed;
		adjacentNodesDistances[nodeyourfeeding][numberofadjacentnodes[nodeyourfeeding]] = distanceaway;
		numberofadjacentnodes[nodeyourfeeding]++;
	}

	bool firstnode(int size)
	{
		int i = 0;
		while (visited[i] == true && i < size)
			i++;
		
		if (i  == size)
			return 1;
		
			cout << endl;
			visited[i] = true;
			checkednodes[0] = i;
			char firstnode = 'A' + i;
			cout << firstnode;
			numberofnodesinsidebox = 1;
			return 0;
		
	}

	void connComp(int size)
	{
		bool breaker = false;
		while (breaker == false)
		{
			loop:
			int counter = 0;

			while (counter < numberofnodesinsidebox)
			{
				int counter2 = 0;
				
				while (counter2 < numberofadjacentnodes[checkednodes[counter]])//checknodes[counter]= the node where checking
					{
						//shortest distance of one node inside box
					if(visited[adjacentNodes[checkednodes[counter]][counter2]] == false)
					{				
						char print = 'A' + adjacentNodes[checkednodes[counter]][counter2];
						cout << " - " << print;
						visited[adjacentNodes[checkednodes[counter]][counter2]] = true;
						checkednodes[numberofnodesinsidebox] = adjacentNodes[checkednodes[counter]][counter2];//adjacentNodes[checkednodes[counter]][counter2] is the new node found
						numberofnodesinsidebox++;
						goto loop;
					}

					counter2++;

				}


				counter++;

			}
			
			cout << endl;
			breaker = true;

		}
				

	}

	Node();
	~Node();
};

