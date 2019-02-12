#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
// Include your transporters function here, or paste it into the file

using namespace std;

typedef vector<int> VI;

int main() {
	ifstream in("transporters.in");
	ifstream out("transporters.out");
	int k, fail = 0;
	in >> k;

	cout << "Will test " << k << " cases\n";

	double secs = 0;
	for (int i = 0; i != k; ++i) {
		int n, t;
		in >> t;
		vector<int> tubes(2*t);
		for (int j = 0; j != t; ++j) {
			in >> tubes[2*j] >> tubes[2*j+1];
			--tubes[2*j];
			--tubes[2*j+1];
		}
		n = *max_element(tubes.begin(), tubes.end());
		++n;
		int ans;
		out >> ans;
		clock_t begin = clock();
		int tx = transporters(n, tubes);
		secs += double(clock()-begin)/CLOCKS_PER_SEC;
		if (ans == tx) cout << "Case " << i << " correct\n";
		else {
			cout << "Case " << i << " incorrect\n";
			cout << "	Expected: " << ans << "\n";
			cout << "	Got: " << tx << "\n";
			++fail;
			cout << "	Continue (n) or view case and exit (c)?: ";
			string resp;
			cin >> resp;
			if (resp == "c") {
				cout << "	n: " << n << "\n";
				cout << "	tubes: [";
				for (int k = 0; k != tubes.size(); ++k) {
					cout << tubes[k] << ", ";
				}
				cout << "]\n";
				exit(-1);
			}
		}
	}

	if (fail == 0) cout << "All cases passed!\n" << "Took " << secs << " seconds\n";
	else cout << fail << " cases failed\n";

	return 0;
}