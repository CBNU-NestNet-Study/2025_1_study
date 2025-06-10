#include <iostream>
using namespace std;

int how_many(int *pay);

int main() {
	int n = 0;
	int pay = 0;
	cin>>n;
	pay = 1000 - n;
	int* renual = &pay;
	int count = 0;
	while (pay > 0) {
		count+=how_many(renual);
		
	}
	cout<<count;

	return 0;
}


int how_many(int *pay) {
	int count = 0;
	if (*pay >= 500) {
		count += ((*pay) / 500);
		*pay -= count * 500;
	}

	//else의 경우는 pay가 500이 안 넘는 경우
	else {
		if (*pay >= 100) {
			count += ((*pay) / 100);
			*pay -= count * 100;
		}
		else {
			if (*pay >= 50) {
				count += ((*pay) / 50);
				*pay -= count * 50;
			}
			else {
				if (*pay >= 10) {
					count += ((*pay) / 10);
					*pay -= count * 10;
				}
				else {
					if (*pay >= 5) {
						count += ((*pay) / 5);
						*pay -= count * 5;
					}
					else {
						count += *pay;
						*pay = 0;
					}
				}
			}
		}



	}
	
	return count;


}
