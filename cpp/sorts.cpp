//============================================================================
// Name        : Sorts.cpp
// Author      : Zhao Hao
// Version     : 1
// Copyright   : 2014, PrizmWorkshop
// Description : Review of sorting algorithms
//============================================================================

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void insertionSort(int *a, int s){
	if(s<2) return;
	int key;

	for(int i =1; i<s; ++i){
		key = a[i];
		int j=i-1;
		while(j>=0 && a[j] > key){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}

int partition(int *a, int lo, int hi){   // two way partition
	int i = lo, j=hi+1;
	int v = a[lo];
	while(true){
		while(a[++i] < v) if(i==hi) break;
		while(v < a[--j]) if(j==lo) break;
		if(i>=j) break;
		swap(a[i], a[j]);
	}
	swap(a[lo], a[j]);
	return j;
}


void quickSort(int *a, int lo, int hi){
	if(hi<=lo) return;
	int j=partition(a, lo, hi);
	quickSort(a, lo, j-1);
	quickSort(a, j+1, hi);
}

void quick3way(int *a, int lo, int hi){   // three way partition quick sort: equal keys in the middle
	if(hi <= lo) return;
	int lt = lo, i =lo+1, gt = hi;
	int key = a[lo];
	while(i <= gt){
		if(a[i] < key) swap(a[lt++], a[i++]);
		else if (a[i] > key) swap(a[i], a[gt--]);
		else i++;
	}
	quick3way(a, lo, lt-1);
	quick3way(a, gt + 1, hi);
}


void shellSort(int *a, int s){
	int h=1;
	while(h<s/3) h=3*h+1;
	while(h>=1){
		for(int i =h; i<s; i++){
			for(int j=i; j>=h && a[j]<a[j-h]; j-=h){
				swap(a[j], a[j-h]);
			}
		}
		h=h/3;
	}
}

static int *aux;

void merge(int *a, int lo, int mid, int hi){
	int i=lo, j=mid+1;
	for(int k = lo; k<= hi; k++){
		aux[k] = a[k];
	}
	for(int k = lo; k<=hi; k++){
		if(i>mid) a[k]=aux[j++];
		else if(j>hi) a[k] = aux[i++];
		else if(aux[j]<aux[i]) a[k] = aux[j++];
		else a[k]=aux[i++];
	}
}

void mergeSort(int *a, int lo, int hi){
	if(hi<=lo) return;
	int mid = lo+(hi-lo)/2;
	mergeSort(a, lo, mid);
	mergeSort(a, mid+1, hi);
	merge(a, lo, mid, hi);
}

void heapSort(int *a, int s){
	// make heap
	

	// heap sort
}

int linearSearch(const int *a, const int s, const int d){
	int i=0;
	for(i=0; i< s; ++i)
		if(a[i]==d) break;
	return i;
}

void slidingWindowBrute(int *a, int s, int w){
	for(int i =0; i<s-w+1; ++i){
		int min=a[i];
		for(int j=i+1; j<i+w; ++j)
			if(a[j] < min) min = a[j];
		cout << min << " ";
	}
	cout << "end" << endl;
}

void slidingWindowLinear(int *a, int s, int w){

}

int gcd(int n, int m){
	int large = n;
	int small = m;
	if(n<m){
		small = n;
		large = m;
	}
	while(large % small != 0 ){
	    int temp = small;
		small = large % small;
		large = temp;
	}
	return small;
}

void reverseWords(string &s) {
//    vector<string> tokens;
//    istringstream iss(s);
//    do{
//        string words;
//        iss >> words;
//        tokens.push_back(words);
//    }while(iss);
//    s.erase();
//    for(int i=tokens.size()-1; i >= 0; --i){
//        s += tokens[i]+" ";
//    }
    int start =-1;
    int end=-1;
    int i;
    string word;
//    string reversed;
    vector<string> wordStack;
    for(i=0; i < s.length(); i++){
        if(start ==-1 && s[i] == ' ') continue;
        if(start ==-1 && s[i] != ' '){
            start = i;
            continue;
        }
        if(start != -1 && s[i] == ' '){
            end = i;
            word = s.substr(start, end-start);
            wordStack.push_back(word);
//            reversed = word + " " + reversed;  // also works but linear time to append.
            start =-1;
            end =-1;
            continue;
        }
    }
    if(start>=0) {
        end =i;
        word = s.substr(start, end-start);
//        reversed = word + " " + reversed;
        wordStack.push_back(word);
    }
    s.erase();
    for(i=wordStack.size()-1; i>0; --i){
       s += wordStack[i]+" ";
    }
    s += wordStack[0];
 //   if(s[s.length()-1]==' ') s.erase(s.end());
 //   if(!s.empty()) s.pop_back();
//    s=reversed;
}

bool isDistinctV(const vector <int> &a){
	int n = a.size();
	int hashe;
	int zeroCount=0;
	vector<int> b(2*n, 0);
	for(int elem : a){
//		cout << "\ninside isDistinct V, element: " << elem << ",";
		if(elem ==0){
			++zeroCount;
			continue;
		}
		if(elem >0) hashe =(1+ 17283*elem) % n;
		else hashe = n + (1-17283*elem) % n;
//		cout << "hash value: " << hashe << endl;
		if(b[hashe]==0) b[hashe] = elem;
		else{
			if(elem == b[hashe]) return false;
//			b[hashe] = elem;
		}
	}
	if(zeroCount >1) return false;
	return true;
}

void swSort(int *a, int lo, int hi){    // sort array into subarrays with 4 ordered elements.
	int i=lo, j=hi, mid=(hi+lo)/2;
	if(lo>=hi) return;
	while(i<j){
		if(a[i] > a[j]) swap(a[i], a[j]);
		i++;
		j--;
	}
	swSort(a,lo, mid);
	swSort(a, mid+1, hi);
}

void mergeSwSort(int *a, int s){    // bottom-up mergeSort ...
	for(int sz=1; sz<s; sz=sz+sz){
		for(int lo=0; lo<s-sz; lo += sz+sz){
			merge(a, lo, lo+sz-1, min(lo+sz+sz-1, s-1));
		}
	}
}

int main() {

	int A[] = {-22,4,-1,12,3,444,9,1,2,38, 38, 0, -9, -22, 46,6};
	int size = sizeof(A)/sizeof(int);

	char cstr[] = "what is this c string?";

	cout << cstr << endl;

	cout << "sliding with 3" << endl;
	slidingWindowBrute(A, size, 3);

    vector<int> testA;
    testA.assign(A, A+size);
    cout << "array A is "<< (isDistinctV(testA)? "":"not ") << "distinct." << endl;

	cout<< "12 is at A[" << linearSearch(A, size, 12) << "]" << endl;

	cout << "input is A[" << size <<"]: ";
	for(int x : A) cout << x << ",";
	cout << endl;

//	insertionSort(A, size);
//	shellSort(A, size);
//	aux = new int[size];
//	mergeSort(A,0, size-1);
	quick3way(A, 0, size-1);
//	quickSort(A, 0, size-1);
//	swSort(A, 0, size-1);
//	mergeSwSort(A, size);
//	delete[] aux;

	cout << "3 way quick Sort output is A[" << size <<"]: ";
	for(int x : A) cout << x << ",";
	cout << endl;

	cout << "gcd of 80844 and 25320 is " << gcd(80844, 25320) << "." << endl;

    string s = "what is this c    string   ";
    reverseWords(s);
    cout << "reverse of [what is this c      string   ] is: " << s << endl;

	return 0;
}
