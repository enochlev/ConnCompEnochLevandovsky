using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include "Node.h"


int main(int argc, char *argv[])

{
	//if there is no argument in the command line it will display ussage
	if (argc == 1)
	{

		cout << "Usage:" << " <(graph).txt>" << "\n\n" << "No Input Dedected, Exiting Program...\n";
	}

	//lets get started
	else {

		ifstream GraphFile;
		GraphFile.open(argv[1]);//the opener

							 //check for if there is actually a valid file
		if (!GraphFile)
		{
			cout << "\tfile open failer\n";
			return 0;//closes the program if no file found
		}

		
		//this will find the size of the graph
		int size = 1;//default size
		char tempchar;
		char tempchar2;
		GraphFile >> tempchar;
		GraphFile >> tempchar2;
		while (tempchar < tempchar2)
		{
			tempchar = tempchar2;
			GraphFile >> tempchar2;
			size++;
		}



		//setup adjacent list for each node
		Node node;
		node.setupSize(size);
		string junkstring;

		
		

		//feeder and input
		int counter = 0;
		while (counter < size)
		{
			int Hcounter = 0;//horizontile counter
			while (Hcounter < size ) {
				int tempint;//distance
				GraphFile >> tempint;
				if (tempint != -1)
				{
					node.feedNode(counter, Hcounter, tempint);

				}
				
				Hcounter++;
			}
			
			
			GraphFile >> tempchar;
			
			counter++;
		}


		//starts by including a aka 0
		


		// 99%of the proccess
		while (1 == 1)
		{
			bool breaker;
			breaker = node.firstnode(size);

			if (breaker == 1)
				break;

			else node.connComp(size);
		}
		


	}
}