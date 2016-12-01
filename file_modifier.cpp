#include <bits/stdc++.h>
using namespace std;

// Just a small tool to manipulate files :)

int main(){
	freopen("mfacedatatest.txt","w",stdout);

	string line;
  	ifstream myfile ("facedatatest");
  	int i = 0;
  	if (myfile.is_open())
  	{
    	while ( getline (myfile,line) )
    	{
    		i++;

			for(int j = 0;j < line.length();j++){
				if(line[j] == '#'){
					cout << 1;
				}
				else{
					cout << 0;
				}
				cout << " ";
			}

			if(i%70 == 0){
				cout << endl;
			}
    	}
    myfile.close();
  	}

  	else cout << "Unable to open file"; 

	return 0;

}