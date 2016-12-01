#include <bits/stdc++.h>

using namespace std;

// Rows and Columns of test data file
#define trainROWS 451
#define trainCOLS 4200

// Rows and Columns of training data file
#define testROWS 150
#define testCOLS 4200

// To remove blank lines at the end of a face
#define blank 0
#define adjust 1

/*

	p00 = probability of 0 given 0 (negative) 
	p01 = probability of 0 given 1 (positive) 
	p10 = probability of 1 given 0 (negative) 
	p11 = probability of 1 given 1 (positive) 

*/

// Structure to store
typedef struct prob
{
	int p00;
	int p01;
	int p10;
	int p11;

	prob() : p00(0), p01(0), p10(0), p11(0){}
}prob;

int main(){

	// Some important declarations
	int total_pos = 0;
	int total_neg = 0;

	// Opening the data train file
	freopen("mfacedatatrain.txt","r",stdin);

	// To store everything from data file into input vector
	vector<vector<int> > input_train(trainROWS,vector<int>(trainCOLS));

	for(int i = 0;i < trainROWS; i++){
		for(int j = 0;j < trainCOLS; j++){
			cin >> input_train[i][j];
		}
	}

	fclose(stdin);

	// Opening the results of data train
	freopen("facedatatrainlabels","r",stdin);

	// To store the given training result
	vector<int> result_train(trainROWS);

	for(int i = 0;i < trainROWS;i++){
		cin >> result_train[i];
		if(result_train[i] == 0){
			total_neg++;
		}
		else{
			total_pos++;
		}
	}

	fclose(stdin);

	// To store the corresponding numerator of prob
	vector<prob> store_prob(trainCOLS-blank);

	for(int j = 0 + adjust;j < trainCOLS-blank;j++){
		for(int i = 0;i < trainROWS;i++){
			if(input_train[i][j] == 0 && result_train[i] == 0){
				store_prob[j].p00++;
			}
			else if(input_train[i][j] == 0 && result_train[i] == 1){
				store_prob[j].p01++;
			}
			else if(input_train[i][j] == 1 && result_train[i] == 0){
				store_prob[j].p10++;
			}
			else if(input_train[i][j] == 1 && result_train[i] == 1){
				store_prob[j].p11++;
			}
		}
	}

	// Storing the data test file into input vector
	vector<vector<int> > input_test(testROWS,vector<int>(testCOLS));

	freopen("mfacedatatest.txt","r",stdin);

	for(int i = 0;i < testROWS; i++){
		for(int j = 0;j < testCOLS; j++){
			cin >> input_test[i][j];
		}
	}

	fclose(stdin);

	freopen("facedatatestlabels","r",stdin);

	// To store the given training result
	vector<int> result_test(testROWS);

	for(int i = 0;i < trainROWS;i++){
		cin >> result_test[i];
	}

	fclose(stdin);

	// To store out predictions of the test data
	vector<int> pred_result_test;

	for(int i = 0;i < testROWS;i++){


		double prod_pp = log((double)total_pos);
		
		double prod_pn = log((double)total_neg);

		for(int j = 0 + adjust;j < testCOLS - blank;j++){
			// Positive Hypothesis
			if(input_test[i][j] == 0){
				prod_pp += (log((double)(max(store_prob[j].p01,1))))-(log((double)total_pos));
			}
			
			else if(input_test[i][j] == 1){
				prod_pp += (log(((double)(max(store_prob[j].p11,1))))-log((double)total_pos));
			}
			
			// Negative Hypothesis
			if(input_test[i][j] == 0){
				prod_pn += (log(((double)(max(store_prob[j].p00,1))))-log((double)total_neg));
			}
			else if(input_test[i][j] == 1){
				prod_pn += (log(((double)(max(store_prob[j].p10,1))))-log((double)total_neg));
			}
		}

		if(prod_pp >= prod_pn){
			pred_result_test.push_back(1);
		}
		else{
			pred_result_test.push_back(0);
		}
	}

	int accuracy = 0;

	//freopen("bay_result.txt","w",stdout);

	for(int i = 0;i < testROWS;i++){
		//cout << result_test[i] << " " << pred_result_test[i] << "---->";
		if(pred_result_test[i] == result_test[i]){
			accuracy++;
			//cout << "right";
		}
		//cout << endl;
	}

	cout << endl << "Accuracy: " << ((double)accuracy/(double)testROWS)*100.0 << '%' << endl;

	return 0;

}