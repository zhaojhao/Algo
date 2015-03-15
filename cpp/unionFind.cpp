// the union find algorithms for Algorithms course
//

#include <cstdlib>
#include <iostream>
#include <vector>

#include <cmath>

using namespace std;

class uf{
private:
	vector<int> vertex;
//	vector<bool> marked;
	int size;
	int count;
public:
	uf(int n);
	~uf();
	void unn(int p, int q);   //union
	int find(int p);
	bool isConnected(int p, int q);
	int componentCount() const {return count;};
	vector<int> getAll() const {return vertex;};
};

uf::uf(int n) : size(n), count(n){
	for(int i = 0; i<size; ++i) {
		vertex.push_back(i);
//		marked.push_back(false);
	}
}

uf::~uf(){

}

void uf::unn(int p, int q){
// quickunion:
	int i = find(p);
	int j = find(q);
	if(i==j) return;

	vertex[i] = j;
	count--;

// quickfind:
//	int pID = find(p);
//	int qID = find(q);
//	if(pID == qID) return;
//	for(int i=0; i<size; ++i)
//		if(vertex[i] == pID) vertex[i] = qID;
//	--count;
}

int uf::find(int p){
	// quickunion:
	 while(p != vertex[p]) p = vertex[p];
	 return p;

	// quickfind:
	// return vertex[p];
}

bool uf::isConnected(int p, int q){
	return find(p)==find(q);
}

int main() {
	int n;
	int x;
	cout << "input the total number: " ;
	cin >> n;
	uf unionfind(n);
	cout << n << endl;
    cout << "\nthe connections (0 to exit): \n";
    cin >> x;
    while(cin && x!=0){
    	int p = x;
    	int q;
    	cin >> q;
    	cout << p << "-" << q << endl;
    	unionfind.unn(p,q);

    	cout << "the data structure: \n";
    	for(int i=0; i<n; i++){
    		if(i==0) cout  << i;
    		else cout << " " << i;
    	}
    	cout << endl;

    	for(int xx : unionfind.getAll()) cout << xx << " ";
    	cout << endl;

    	cin >> x;
	}
    cout << endl;
	cout << "there are total " << unionfind.componentCount() << " component" << endl;

	return EXIT_SUCCESS;
}
