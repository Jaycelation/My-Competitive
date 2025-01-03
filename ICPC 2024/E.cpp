#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<unordered_map<int, int>> segTree;
vector<int> arr;

void build(int node, int start, int end) {
    if (start == end) {
        segTree[node][arr[start]]++;
    } else {
        int mid = (start + end) / 2;
        int leftNode = 2 * node + 1;
        int rightNode = 2 * node + 2;

        build(leftNode, start, mid);
        build(rightNode, mid + 1, end);
		//Hop nhat tan suat
        segTree[node] = segTree[leftNode];
        for (const auto &it : segTree[rightNode]) {
            segTree[node][it.first] += it.second;
        }
    }
}

//Query [L, R]
unordered_map<int, int> query(int node, int start, int end, int L, int R) {
    if (R < start || end < L) {
        return unordered_map<int, int>();
    }
    if (L <= start && end <= R) {
        return segTree[node];
    }
    int mid = (start + end) / 2;
    int leftNode = 2 * node + 1;
    int rightNode = 2 * node + 2;

    unordered_map<int, int> leftFreq = query(leftNode, start, mid, L, R);
    unordered_map<int, int> rightFreq = query(rightNode, mid + 1, end, L, R);

    unordered_map<int, int> result = leftFreq;
    for (const auto &it : rightFreq) {
        result[it.first] += it.second;
    }
    return result;
}

void queryXOR(int L, int R, int n) {
    unordered_map<int, int> freq = query(0, 0, n - 1, L, R);
	
	vector<int> val;
    cout << "Phan tu co so lan xuat hien chan trong doan [" << L+1 << ", " << R+1 << "]: ";
    for (const auto &it : freq) {
        if (it.second % 2 == 0) {
			cout << it.first << " ";
			val.push_back(it.first);
    	}
    }
    if (val.size() == 0)
    	cout << 0 << "\n"; 
	else {
	    long long result = val[0];
	    for (int i = 1; i < val.size(); ++i) {
	    	result ^= val[i];
		}
	    cout << "\nTong XOR cac phan tu xuat hien chan trong doan la: " << result << "\n";		
	}
}

int main() {
    int n, q;
    cin >> n;
    arr.resize(n);
    segTree.resize(4 * n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    build(0, 0, n - 1);
	cin >> q;
	
    for (int i = 0; i < q; ++i) {
        int L, R;
        cin >> L >> R;  
        queryXOR(L-1, R-1, n);
    }

    return 0;
}
